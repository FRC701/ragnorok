#include "SetShooter.h"
#include "../Subsystems/Shooter.h"
std::shared_ptr<Shooter> shooter = Shooter::getInstance();
SetShooter::SetShooter(double speed) : Command(),
		mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Shooter::getInstance().get());

}

// Called just before this Command runs the first time
void SetShooter::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetShooter::Execute() {
	shooter->SetShooter(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetShooter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooter::Interrupted() {

}
