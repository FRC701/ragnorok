#include "SetShooter.h"
#include "../Subsystems/Shooter.h"
#include <iostream>

SetShooter::SetShooter(double speed) :
    mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Shooter::getInstance().get());
}

// Called once when the command executes
void SetShooter::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void SetShooter::Execute() {
  Shooter::getInstance()->SetShooter(mSpeed);
  std::cout << "Shooter speed Set" << mSpeed << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool SetShooter::IsFinished() {
  return true;
}

// Called once after isFinished returns true
void SetShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooter::Interrupted() {

}

void SetShooter::Nudge(double value) {
  mSpeed += value;
}
