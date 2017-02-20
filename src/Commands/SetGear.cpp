#include "SetGear.h"

SetGear::SetGear(GearPickup::PickupValue value) :
    mValue(value) {
 Requires(GearPickup::getInstance().get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void SetGear::Initialize() {
  GearPickup::getInstance()->SetGear(mValue);
}
