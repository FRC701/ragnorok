#include "DefaultIntake.h"

DefaultIntake::DefaultIntake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DefaultIntake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DefaultIntake::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DefaultIntake::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DefaultIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefaultIntake::Interrupted() {

}
