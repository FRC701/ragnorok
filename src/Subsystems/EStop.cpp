/*
 * EStop.cpp
 *
 */

#include "EStop.h"

EStop::EStop()
: timerStarted(false)
{

}

EStop::~EStop()
{

}

static const double kMinStopped = 0.001;
static const double kMinSpeed = 0.001;

bool EStop::ShouldStop(double setSpeed, double currentSpeed)
{
  bool shouldStop = kDontStop;

  bool isSetSpeedStopped = fabs(setSpeed) < kMinStopped;
  bool isCurrentSpeedStopped = fabs(currentSpeed) < kMinSpeed;

  if (isCurrentSpeedStopped && !isSetSpeedStopped) {
    shouldStop = kStop;
  } else {
    StopTimer();
  }

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



