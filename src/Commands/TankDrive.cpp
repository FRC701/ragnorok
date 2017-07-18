#include "Robot.h"
#include "TankDrive.h"
#include "../Subsystems/Chassis.h"

TankDrive::TankDrive(bool automaticShifting) :
  mAutomaticShifting(automaticShifting) {
  // Use requires() here to declare subsystem dependencies
  Requires(Chassis::getInstance().get());
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {
  Chassis::getInstance()->SetupDrive();
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
  std::shared_ptr<Chassis> chassis = Chassis::getInstance();
  std::shared_ptr<OI> oi = OI::getInstance();

  double left = oi->getDriverLeftYAxis() * -1.0;
  double right = oi->getDriverRightYAxis() * -1.0;

  chassis->SetTankDrive(left, right);

  SmartDashboard::PutNumber("Right Drive Encoder Value",chassis->GetRightEncRPM());

  if (mAutomaticShifting){
  	// AutoShifting();
  }
  SmartDashboard::PutBoolean("AutoShifting", mAutomaticShifting);
}
// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void TankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {

}

void TankDrive::SetAutomaticShifting(bool automaticShifting) {
  mAutomaticShifting = automaticShifting;
}

bool TankDrive::IsAutoShifterEnabled(){
  return mAutomaticShifting;
}

void TankDrive::AutoShifting() {
  std::shared_ptr<Chassis> chassis = Chassis::getInstance();

  if (chassis->IsShifterHigh()) {
  	if (fabs(chassis->GetLeftEncRPM()) <= kShiftDownVelocity
        && fabs(chassis->GetRightEncRPM()) <= kShiftDownVelocity) {
      chassis->SetShifter(Chassis::kShifterLow);
    }
  }
  else {
    if (fabs(chassis->GetLeftEncRPM()) >= kShiftUpVelocity
        || fabs(chassis->GetRightEncRPM()) >= kShiftUpVelocity) {
    chassis->SetShifter(Chassis::kShifterHigh);
    }
  }
}
