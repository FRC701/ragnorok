#include "TimedDrive.h"
#include "Subsystems/Chassis.h"

TimedDrive::TimedDrive(double timeout, double leftSpeed,double rightSpeed) : TimedCommand(timeout),
  mLeftSpeed(leftSpeed), mRightSpeed(rightSpeed) {
	// Use Requires() here to declare subsystem dependencies
  Requires(Chassis::getInstance().get());
}

// Called just before this Command runs the first time
void TimedDrive::Initialize() {
  Chassis::getInstance()->SetupDrive();
  Chassis::getInstance()->ConfigPeakOutput(8.5,8.5);
}

// Called repeatedly when this Command is scheduled to run
void TimedDrive::Execute() {
  Chassis::getInstance()->SetTankDrive(mLeftSpeed, mRightSpeed);
}

// Called once after command times out
void TimedDrive::End() {
  Chassis::getInstance()->SetTankDrive(0.0, 0.0);
  Chassis::getInstance()->ConfigPeakOutput(12,12);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedDrive::Interrupted() {
  Chassis::getInstance()->SetTankDrive(0.0, 0.0);
  Chassis::getInstance()->ConfigPeakOutput(12,12);
}
