#include "SetConveyor.h"
#include "../Subsystems/BallConveyor.h"

SetConveyor::SetConveyor(double conveyorSpeed) :
  mConveyorSpeed(conveyorSpeed)
{
	// Use Requires() here to declare subsystem dependencies
  Requires(BallConveyor::getInstance().get());
}

// Called just before this Command runs the first time
void SetConveyor::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetConveyor::Execute() {
  BallConveyor::getInstance()->SetConveyor(mConveyorSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetConveyor::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetConveyor::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetConveyor::Interrupted() {

}
