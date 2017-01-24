#include "SetGear.h"
#include "Subsystems/GearPickup.h"

SetGear::SetGear(GearPickup::PickupValue value) :
    mValue(value) {
 Requires(GearPickup::getInstance().get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void SetGear::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetGear::Execute() {
  GearPickup::getInstance()->SetGear(mValue);

}

// Make this return true when this Command no longer needs to run execute()
bool SetGear::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetGear::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetGear::Interrupted() {

}
