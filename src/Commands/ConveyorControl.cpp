#include "ConveyorControl.h"
#include "../Subsystems/BallConveyor.h"

ConveyorControl::ConveyorControl(double speed) :
  mSpeed(speed)    {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(BallConveyor::getInstance().get());
}

// Called just before this Command runs the first time
void ConveyorControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ConveyorControl::Execute() {
  BallConveyor::getInstance()->ConveyorControl(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ConveyorControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ConveyorControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ConveyorControl::Interrupted() {

}
