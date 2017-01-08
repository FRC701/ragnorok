#include "CANTalon.h"
#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

Chassis::Chassis() : Subsystem("Chassis"),
  right1Wheel(RobotMap::chassisRight1Wheel),
  right2Wheel(RobotMap::chassisRight2Wheel),
  right3Wheel(RobotMap::chassisRight3Wheel),
  left1Wheel(RobotMap::chassisLeft1Wheel),
  left2Wheel(RobotMap::chassisLeft2Wheel),
  left3Wheel(RobotMap::chassisLeft3Wheel) {

  right1Wheel->SetInverted(true);

  right2Wheel->SetControlMode(CANTalon::kFollower);
  right2Wheel->Set(RobotMap::kIDRightWheel1);
  right3Wheel->SetControlMode(CANTalon::kFollower);
  right3Wheel->Set(RobotMap::kIDRightWheel1);

  left2Wheel->SetControlMode(CANTalon::kFollower);
  left2Wheel->Set(RobotMap::kIDLeftWheel1);
  left3Wheel->SetControlMode(CANTalon::kFollower);
  left3Wheel->Set(RobotMap::kIDLeftWheel1);
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
  right2Wheel->Set(right);
  right3Wheel->Set(right);

  left1Wheel->Set(left);
  left2Wheel->Set(left);
  left3Wheel->Set(left);
}
