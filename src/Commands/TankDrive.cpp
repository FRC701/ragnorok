#include "Robot.h"
#include "TankDrive.h"
#include "../Subsystems/Chassis.h"

TankDrive::TankDrive(): Command() {
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
  Requires(Chassis::getInstance().get());
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
  std::shared_ptr<OI> oi = OI::getInstance();
  std::shared_ptr<Chassis> chassis = Chassis::getInstance();
  double left = oi->getDriverLeftYAxis();
  double right = oi->getDriverRightYAxis();

  Chassis::getInstance()->SetTankDrive(left, right);

  SmartDashboard::PutNumber("Right Drive Encoder Value",Chassis::getInstance()->GetRightEncRPM());

  static const double kShiftUpVelocity =  1000;

  static const double kShiftDownVelocity = 0.75 * kShiftUpVelocity;

  if (chassis->IsShifterHigh()) {
    if (chassis->GetLeftEncRPM() <= kShiftDownVelocity
      || chassis->GetRightEncRPM() <= kShiftDownVelocity) {
    chassis->SetShifter(Chassis::kShifterLow);
    }
  }
  else {
    if (chassis->GetLeftEncRPM() >= kShiftUpVelocity
        || chassis->GetRightEncRPM() <= kShiftUpVelocity) {
    chassis->SetShifter(Chassis::kShifterHigh);
    }
  }
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
