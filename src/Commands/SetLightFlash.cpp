#include "SetLightFlash.h"
#include "LightsOn.h"
#include "../Subsystems/Lights.h"

SetLightFlash::SetLightFlash(double timeFlashing):
mTimeFlashing(timeFlashing) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void SetLightFlash::Initialize() {
Lights::getInstance()->GetLightsOnCommand()->SetTimeFlashing(mTimeFlashing);
}
