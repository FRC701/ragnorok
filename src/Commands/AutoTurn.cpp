#include "AutoTurn.h"
#include "Subsystems/Chassis.h"

AutoTurn::AutoTurn(TurnSide side, double distance)
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
  switch(mSide)
  {
    case kTurnLeftSide:
      Chassis::getInstance()->SetSidePercentVBus(Chassis::kDriveRightSide);
      Chassis::getInstance()->SetTankDrive(mDistance, 0.0);
    break;
    case kTurnRightSide:
      Chassis::getInstance()->SetSidePercentVBus(Chassis::kDriveLeftSide);
      Chassis::getInstance()->SetTankDrive(0.0, mDistance);
    break;
  }


}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() {
  switch (mSide)
  {
    case kTurnLeftSide:
      return (fabs (Chassis::getInstance ()->GetLeftDrivePosition ())
           >= fabs (Chassis::getInstance ()->GetLeftDriveSetPoint ()));
      break;
    case kTurnRightSide:
      return (fabs (Chassis::getInstance ()->GetRightDrivePosition ())
           >= fabs (Chassis::getInstance ()->GetRightDriveSetPoint ()));
      break;
  }

  return false;
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
