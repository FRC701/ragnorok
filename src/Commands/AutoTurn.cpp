#include "AutoTurn.h"
#include "../Subsystems/Chassis.h"

AutoTurn::AutoTurn(char side, double distance)
: mSide(side),mDistance(distance ){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Chassis::getInstance().get());
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
  Chassis::getInstance()->ConfigPeakOutput(8);
  Chassis::getInstance()->SetupPID();
  Chassis::getInstance()->ZeroPosition();
  Chassis::getInstance()->SetShifter(Chassis::kShifterLow);
  if(mSide == 'l') {
    Chassis::getInstance()->SetSidePercentVBUS('r');
    Chassis::getInstance()->SetTankDrive(mDistance, 0.0);
  }
  else if(mSide == 'r') {
    Chassis::getInstance()->SetSidePercentVBUS('l');
    Chassis::getInstance()->SetTankDrive(0.0,mDistance);
  }


}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() {
  if (mSide == 'l') {
    return (fabs(Chassis::getInstance()->GetLeftDrivePosition()) >= fabs(Chassis::getInstance()->GetLeftDriveSetPoint()));
  }

  else if (mSide == 'r') {
    return (fabs(Chassis::getInstance()->GetRightDrivePosition()) >= fabs(Chassis::getInstance()->GetRightDriveSetPoint()));
  }
 else return false;
}

// Called once after isFinished returns true
void AutoTurn::End() {
  Chassis::getInstance()->ZeroPosition();
  Chassis::getInstance()->SetupDrive();
  Chassis::getInstance()->ConfigPeakOutput(12);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {
  Chassis::getInstance()->ZeroPosition();
  Chassis::getInstance()->SetupDrive();
  Chassis::getInstance()->ConfigPeakOutput(12);
}
