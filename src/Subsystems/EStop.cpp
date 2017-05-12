#include "EStop.h"
#include <cmath>
#include "Commands/CommandGroup.h"

EStop::EStop(double defaultStallTime)
: stallTime(0.0),
  mDefaultStallTime(defaultStallTime),
  timerStarted(false),
  wasSetSpeedStopped(true)
{

}

EStop::~EStop()
{

}

void EStop::CancelCurrentCommand(Command* command)
{
  for (Command* group = command->GetGroup(); group; group = command->GetGroup()) {
    command = group;
  }
  command->Cancel();
}

static const double kMinStopped = 0.001;
static const double kMinSpeed = 0.001;

bool EStop::ShouldStop(double setSpeed, double currentSpeed)
{
  bool shouldStop = kDontStop;

  bool isSetSpeedStopped = fabs(setSpeed) < kMinStopped;
  bool isCurrentSpeedStopped = fabs(currentSpeed) < kMinSpeed;

  static const double kRampTimeSeconds = 0.5;

  if (isCurrentSpeedStopped && !isSetSpeedStopped) {
    if (!timerStarted) {

      if (wasSetSpeedStopped) {
        stallTime = mDefaultStallTime + kRampTimeSeconds;
      }
      else {
        stallTime = mDefaultStallTime;
      }

      timer.Start();
      timerStarted = true;
    }
    shouldStop = timer.HasPeriodPassed(stallTime);
  }
  else {
    StopTimer();
  }

  wasSetSpeedStopped = isSetSpeedStopped;
  return shouldStop;
}

void EStop::StopTimer()
{
  if (timerStarted) {
    timerStarted = false;
    timer.Stop();
    timer.Reset();
  }
}
