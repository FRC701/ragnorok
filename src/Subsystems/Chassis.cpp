#include "CANTalon.h"
#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

Chassis::Chassis() : Subsystem("Chassis"),
  right1Wheel(RobotMap::chassisRight1Wheel),
  right2Wheel(RobotMap::chassisRight2Wheel),
  left1Wheel(RobotMap::chassisLeft1Wheel),
  left2Wheel(RobotMap::chassisLeft2Wheel)
 {

  right1Wheel->SetInverted(true);

  right2Wheel->SetControlMode(CANTalon::kFollower);
  right2Wheel->Set(RobotMap::kIDRightWheel1);

  left2Wheel->SetControlMode(CANTalon::kFollower);
  left2Wheel->Set(RobotMap::kIDLeftWheel1);
}

void Chassis::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

  SetDefaultCommand(new TankDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::SetTankDrive(double left, double right) {
  right1Wheel->Set(right);
  left1Wheel->Set(left);
}
