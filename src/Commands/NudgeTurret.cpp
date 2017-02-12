#include "NudgeTurret.h"
#include "SetTurret.h"
#include "../Subsystems/Turret.h"

NudgeTurret::NudgeTurret(double nudge)
: mNudge(nudge) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void NudgeTurret::Initialize() {
	std::shared_ptr<Turret> turret = Turret::getInstance();
	turret->GetSetPositionCommand()->SetPosition(turret->GetSetPoint() + mNudge);
}
