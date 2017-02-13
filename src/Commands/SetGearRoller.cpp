#include "SetGearRoller.h"
#include "Subsystems/GearPickup.h"

SetGearRoller::SetGearRoller(double _rollerSpeedRPM)
: rollerSpeedRPM(_rollerSpeedRPM) {
	// Use Requires() here to declare subsystem dependencies
	Requires(GearPickup::getInstance().get());
}

// Called just before this Command runs the first time
void SetGearRoller::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetGearRoller::Execute() {
  GearPickup::getInstance()->SetRollerSpeedRPM(rollerSpeedRPM);
}

// Make this return true when this Command no longer needs to run execute()
bool SetGearRoller::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetGearRoller::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetGearRoller::Interrupted() {

}