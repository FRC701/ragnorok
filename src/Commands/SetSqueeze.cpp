#include "SetSqueeze.h"

SetSqueeze::SetSqueeze(GearPickup::SqueezeValue value) :
	mValue(value) {
	Requires(GearPickup::getInstance().get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void SetSqueeze::Initialize() {

}
