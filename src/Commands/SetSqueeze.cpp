#include "SetSqueeze.h"

SetSqueeze::SetSqueeze(GearPickup::SqueezeValue value) :
	mValue(value) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(GearPickup::getInstance().get());
}

// Called just before this Command runs the first time
void SetSqueeze::Initialize() {
  GearPickup::getInstance()->SetSqueeze(mValue);
}
