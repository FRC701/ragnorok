#include "LightsOn.h"
#include "Subsystems/Lights.h"
#include "Subsystems/GearPickup.h"

LightsOn::LightsOn() : flash(&LightsOn::Notify, this), flashed(false) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Lights::getInstance().get());
}

// Called just before this Command runs the first time
void LightsOn::Initialize() {
  Lights::getInstance()->SetGlow(Relay::kOn);
}

// Called repeatedly when this Command is scheduled to run
void LightsOn::Execute() {
  if(GearPickup::getInstance()->IsGearIn()){
    if(! flashed) {
      flash.StartPeriodic(.125);
      flashed = true;
    }
  }
  else {
    flash.Stop();
    flashed = false;
    Lights::getInstance()->SetGlow(Relay::kOn);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool LightsOn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LightsOn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LightsOn::Interrupted() {

}

void LightsOn::Notify() {
  Lights::getInstance()->ToggleGlow();
}
