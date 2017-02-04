#include "NudgeShooter.h"
#include "SetShooter.h"
#include "../Subsystems/Shooter.h"

NudgeShooter::NudgeShooter(double nudge)
: mNudge(nudge) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void NudgeShooter::Initialize() {
  std::shared_ptr<Shooter> shooter = Shooter::getInstance();
  shooter->GetSetShooterCommand()->SetSpeed(shooter->GetSetPoint() + mNudge);
}
