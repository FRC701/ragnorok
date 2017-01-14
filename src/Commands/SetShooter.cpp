#include "SetShooter.h"
#include "../Subsystems/Shooter.h"

SetShooter::SetShooter(double speed) :
    mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Shooter::getInstance().get());
}

// Called once when the command executes
void SetShooter::Initialize() {
	 Shooter::getInstance()->SetShooter(mSpeed);
}
