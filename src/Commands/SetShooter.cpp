#include "SetShooter.h"
std::shared_ptr<Shooter> shooter = Shooter::getInstance();
SetShooter::SetShooter(double speed) : Command(),
		mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Shooter::getInstance().get());
}

// Called once when the command executes
void SetShooter::Initialize() {
	shooter->SetShooter(mSpeed);
}
