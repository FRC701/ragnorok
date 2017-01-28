#include "ToggleGear.h"
#include "Subsystems/GearPickup.h"

ToggleGear::ToggleGear() {
  Requires(GearPickup::getInstance().get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleGear::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleGear::Execute() {
  GearPickup::PickupValue value
    = GearPickup::getInstance()->IsGearUp() ? GearPickup::kGearDown : GearPickup::kGearUp;
  GearPickup::getInstance()->SetGear(value);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleGear::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleGear::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleGear::Interrupted() {

}
