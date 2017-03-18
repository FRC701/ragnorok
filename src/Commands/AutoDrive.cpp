#include "AutoDrive.h"
#include "../Subsystems/Chassis.h"

AutoDrive::AutoDrive(double leftDistance, double rightDistance):
  mLeftDistance(leftDistance), mRightDistance(rightDistance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Chassis::getInstance().get());
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
  Chassis::getInstance()->SetupPID();
  Chassis::getInstance()->SetTankDrive(mLeftDistance, mRightDistance);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	  return (fabs(Chassis::getInstance()->GetDrivePosition()) >= fabs(Chassis::getInstance()->GetDriveSetPoint()));
}

// Called once after isFinished returns true
void AutoDrive::End() {
  Chassis::getInstance()->ZeroPosition();
  Chassis::getInstance()->SetupDrive();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {
  Chassis::getInstance()->ZeroPosition();
  Chassis::getInstance()->SetupDrive();
}
