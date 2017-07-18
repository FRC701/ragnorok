#include "ToggleSqueeze.h"
#include "Subsystems/GearPickup.h"

ToggleSqueeze::ToggleSqueeze() {
	// Use Requires() here to declare subsystem dependencies
	Requires(GearPickup::getInstance().get());
}

// Called just before this Command runs the first time
void ToggleSqueeze::Initialize() {
	GearPickup::SqueezeValue value
		= GearPickup::getInstance()->IsSqueezeOpen() ? GearPickup::kSqueezeClosed : GearPickup::kSqueezeOpen;
	GearPickup::getInstance()->SetSqueeze(value);
}
