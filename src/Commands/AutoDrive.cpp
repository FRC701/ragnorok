#include "AutoDrive.h"
#include "../Subsystems/Chassis.h"

AutoDrive::AutoDrive(double leftDistance, double rightDistance):
  mLeftDistance(leftDistance), mRightDistance(rightDistance) {
	// Use Requires() here to declare subsystem dependencies
  Requires(Chassis::getInstance().get());
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
  Chassis::getInstance()->ConfigPeakOutput(7,6.5);
  Chassis::getInstance()->SetupPID();
  Chassis::getInstance()->ZeroPosition();
  Chassis::getInstance()->SetShifter(Chassis::kShifterLow);
  Chassis::getInstance()->SetTankDrive(mLeftDistance, mRightDistance);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	  return (fabs(Chassis::getInstance()->GetRightDrivePosition()) >= fabs(Chassis::getInstance()->GetRightDriveSetPoint()))
	   && (fabs(Chassis::getInstance()->GetLeftDrivePosition()) >= fabs(Chassis::getInstance()->GetLeftDriveSetPoint()));
}

// Called once after isFinished returns true
void AutoDrive::End() {
  Chassis::getInstance()->ZeroPosition();
  Chassis::getInstance()->SetupDrive();
  Chassis::getInstance()->ConfigPeakOutput(12,12);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {
  Chassis::getInstance()->ZeroPosition();
  Chassis::getInstance()->SetupDrive();
  Chassis::getInstance()->ConfigPeakOutput(12,12);
}
