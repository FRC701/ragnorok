#include "ToggleLifter.h"
#include "../Subsystems/Lifter.h"

ToggleLifter::ToggleLifter(double speed) :
		mSpeed(speed), turnOn(true)	{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Lifter::getInstance().get());
}

// Called just before this Command runs the first time
void ToggleLifter::Initialize() {
  Lifter::getInstance()->SetBrake();

  double current = Lifter::getInstance()->GetCurrent();
  if(current <= 0) {
	  turnOn = true;
  }
  else if (current > 0) {
	  turnOn = false;
  }
}

// Called repeatedly when this Command is scheduled to run
void ToggleLifter::Execute() {
  if(turnOn) {
	  Lifter::getInstance()->SetLifter(mSpeed);
  }
  else if (!turnOn) {
	  Lifter::getInstance()->SetLifter(0.0);
  }

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLifter::IsFinished() {
	return false;
}
//
// Called once after isFinished returns true
void ToggleLifter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLifter::Interrupted() {

}
