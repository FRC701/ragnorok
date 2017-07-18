#include "SetIntake.h"
#include "../Subsystems/Intake.h"

SetIntake::SetIntake(double speed)
: mSpeed(speed)
{
	// Use Requires() here to declare subsystem dependencies
   Requires(Intake::getInstance().get());
}

// Called just before this Command runs the first time
void SetIntake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetIntake::Execute() {
  Intake::getInstance()->SetIntake(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetIntake::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetIntake::Interrupted() {

}
