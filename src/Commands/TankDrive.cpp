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
  double left = oi->getDriverLeftYAxis();
  double right = oi->getDriverRightYAxis();

  Chassis::getInstance()->SetTankDrive(left, right);

  //Automatic Shifters
 SmartDashboard::PutNumber("Right Drive Encoder Value",Chassis::getInstance()->GetRightEncRPM());
 SmartDashboard::PutNumber("Right Throttle Value", right);
 SmartDashboard::PutNumber("Right Throttle Value", left);
  double shiftUpVelocity =  100;

  double shiftDownVelocity = 50;

  const double kThrottle = 0.8;

  if ((Chassis::getInstance()->IsShifterHigh() == !Chassis::ShifterValue::kShifterHigh)
      && (Chassis::getInstance()->GetLeftEncRPM() >= shiftUpVelocity
      || Chassis::getInstance()->GetRightEncRPM() >= shiftUpVelocity)
     && (left >= kThrottle
        || right >= kThrottle) )
  {
    Chassis::getInstance()->SetShifter(Chassis::ShifterValue::kShifterHigh);
  }

  if ((Chassis::getInstance()->IsShifterHigh() == Chassis::ShifterValue::kShifterHigh)
        && (Chassis::getInstance()->GetLeftEncRPM() <= shiftDownVelocity
        && Chassis::getInstance()->GetRightEncRPM() <= shiftDownVelocity)
        && (left <= 0.1
        && right <= 0.1))
  {
    Chassis::getInstance()->SetShifter(Chassis::ShifterValue::kShifterLow);
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
