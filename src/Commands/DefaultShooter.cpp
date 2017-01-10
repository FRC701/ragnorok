#include "DefaultShooter.h"
#include "../Subsystems/Shooter.h"


// Called just before this Command runs the first time
DefaultShooter::DefaultShooter(): Command() {
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
  Requires(Shooter::getInstance().get());
}

void DefaultShooter::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DefaultShooter::Execute() {
	shooter->SetShooter(shooter->GetShooterspeed());
}

// Make this return true when this Command no longer needs to run execute()
bool DefaultShooter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DefaultShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefaultShooter::Interrupted() {

}
