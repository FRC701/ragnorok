#include "SetGearRoller.h"
#include "Subsystems/GearPickup.h"

SetGearRoller::SetGearRoller(double _rollerSpeedRPM)
: rollerSpeedRPM(_rollerSpeedRPM), timeout() {
	// Use Requires() here to declare subsystem dependencies
	Requires(GearPickup::getInstance().get());
}

// Called just before this Command runs the first time
void SetGearRoller::Initialize() {
  timeout.Start();
}

// Called repeatedly when this Command is scheduled to run
void SetGearRoller::Execute() {
  GearPickup::getInstance()->SetRollerSpeedRPM(rollerSpeedRPM);
}

// Make this return true when this Command no longer needs to run execute()
bool SetGearRoller::IsFinished() {
  if (rollerSpeedRPM > 0)
    return GearPickup::getInstance()->IsGearIn();
  else if (rollerSpeedRPM < 0)
    if(timeout.HasPeriodPassed(2))
      return true;
  else
    return !(GearPickup::getInstance()->IsGearIn());
  else
    return false;
}

// Called once after isFinished returns true
void SetGearRoller::End() {
  GearPickup::getInstance()->SetRollerSpeedRPM(0.0);
  timeout.Stop();
  timeout.Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetGearRoller::Interrupted() {
  GearPickup::getInstance()->SetRollerSpeedRPM(0.0);
  timeout.Stop();
  timeout.Reset();
}
