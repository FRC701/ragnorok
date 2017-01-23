#include "NudgeShooter.h"
#include "Subsystems/Shooter.h"
NudgeShooter::NudgeShooter(double nudge):
  mNudge(nudge){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Shooter::getInstance().get());
  speed = 0;
}

// Called just before this Command runs the first time
void NudgeShooter::Initialize() {

  speed = Shooter::getInstance()->GetSetPoint() + mNudge;
}

// Called repeatedly when this Command is scheduled to run
void NudgeShooter::Execute() {

  Shooter::getInstance()->SetShooter(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool NudgeShooter::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void NudgeShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NudgeShooter::Interrupted() {

}
