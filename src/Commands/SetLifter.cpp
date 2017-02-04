#include "SetLifter.h"
#include "../Subsystems/Lifter.h"

SetLifter::SetLifter(double speed) :
		mSpeed(speed)	{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Lifter::getInstance().get());
}

// Called just before this Command runs the first time
void SetLifter::Initialize() {
  Lifter::getInstance()->SetBrake();
}

// Called repeatedly when this Command is scheduled to run
void SetLifter::Execute() {
	Lifter::getInstance()->SetLifter(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetLifter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetLifter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLifter::Interrupted() {

}
