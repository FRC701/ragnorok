#include "CANTalon.h"
#include "LiveWindow/LiveWindow.h"
#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

const char Chassis::kSubsystemName[] = "Chassis";

std::shared_ptr<Chassis> Chassis::self;

std::shared_ptr<Chassis> Chassis::getInstance() {
  if (! self) {
     self = std::make_shared<Chassis>();
  }
  return self;
}


Chassis::Chassis() : Subsystem(kSubsystemName),
  right1Wheel(RobotMap::kIDRightWheel1),
  right2Wheel(RobotMap::kIDRightWheel2),
  left1Wheel(RobotMap::kIDLeftWheel1),
  left2Wheel(RobotMap::kIDLeftWheel2),
  Shifter(RobotMap::kIDShitftingHigh, RobotMap::kIDShitftingLow)
  {

  frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

  lw->AddActuator(kSubsystemName , "Right1Wheel", right1Wheel);
  lw->AddActuator(kSubsystemName , "Right2Wheel", right2Wheel);
  lw->AddActuator(kSubsystemName , "Left1Wheel", left1Wheel);
  lw->AddActuator(kSubsystemName , "Left2Wheel", left2Wheel);

  right1Wheel.SetInverted(true);

  right2Wheel.SetControlMode(CANTalon::kFollower);
  right2Wheel.Set(RobotMap::kIDRightWheel1);

  left2Wheel.SetControlMode(CANTalon::kFollower);
  left2Wheel.Set(RobotMap::kIDLeftWheel1);

}

void Chassis::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

  SetDefaultCommand(new TankDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::SetTankDrive(double left, double right) {
  right1Wheel.Set(right);
  left1Wheel.Set(left);
}
