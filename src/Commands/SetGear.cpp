#include "SetGear.h"

SetGear::SetGear(GearPickup::PickupValue value) :
    mValue(value) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(GearPickup::getInstance().get());
}

// Called just before this Command runs the first time
void SetGear::Initialize() {
  GearPickup::getInstance()->SetGear(mValue);
}
