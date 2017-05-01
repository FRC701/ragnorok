#include "StopShooter.h"
#include "Subsystems/Shooter.h"

StopShooter::StopShooter() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void StopShooter::Initialize() {
  std::shared_ptr<Shooter> shooter = Shooter::getInstance();
  shooter->GetSetShooterCommand()->SetSpeed(shooter->GetSetPoint());
}
