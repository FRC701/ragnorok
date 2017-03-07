#include "ToggleGear.h"
#include "Subsystems/GearPickup.h"

ToggleGear::ToggleGear() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(GearPickup::getInstance().get());
}

// Called just before this Command runs the first time
void ToggleGear::Initialize() {
  GearPickup::PickupValue value
    = GearPickup::getInstance()->IsGearUp() ? GearPickup::kGearDown : GearPickup::kGearUp;
  GearPickup::getInstance()->SetGear(value);
}
