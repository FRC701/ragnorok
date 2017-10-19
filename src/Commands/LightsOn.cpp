	#include "LightsOn.h"
#include "../Subsystems/Lights.h"
#include "../Subsystems/GearPickup.h"

LightsOn::LightsOn() : flash(&LightsOn::Notify, this), flashed(false),
	mTimeFlashing(0), shouldFlash(false) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Lights::getInstance().get());
}

// Called just before this Command runs the first time
void LightsOn::Initialize() {
  Lights::getInstance()->SetGlow(Lights::LightsValue::kLightsOn);
}

// Called repeatedly when this Command is scheduled to run
void LightsOn::Execute() {

  if(shouldFlash){
    if(! flashed) {
      flash.StartPeriodic(.125);
      flashed = true;
    }
  }
  if(timeToFlash.HasPeriodPassed(mTimeFlashing)) {
    flash.Stop();
    flashed = false;
    Lights::getInstance()->SetGlow(Lights::LightsValue::kLightsOn);
    timeToFlash.Stop();
    timeToFlash.Reset();
    shouldFlash = false;
  }
}

// Make this return true when this Command no longer needs to run execute()
bool LightsOn::IsFinished() {
	return timeToFlash.HasPeriodPassed(mTimeFlashing);
}

// Called once after isFinished returns true
void LightsOn::End() {
  flash.Stop();
  flashed = false;
  Lights::getInstance()->SetGlow(Lights::LightsValue::kLightsOn);
  timeToFlash.Stop();
  timeToFlash.Reset();
  shouldFlash = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LightsOn::Interrupted() {
  flash.Stop();
  flashed = false;
  Lights::getInstance()->SetGlow(Lights::LightsValue::kLightsOn);
  timeToFlash.Stop();
  timeToFlash.Reset();
  shouldFlash = false;
}

void LightsOn::Notify() {
  Lights::getInstance()->ToggleGlow();
}

void LightsOn::SetTimeFlashing(double timeFlashing){
	mTimeFlashing = timeFlashing;
	timeToFlash.Start();
	shouldFlash = true;
}
