#include "CANTalon.h"
#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

Chassis::Chassis() : Subsystem("Chassis"),
left1Wheel(RobotMap::chassisLeft1Wheel),
left2Wheel(RobotMap::chassisLeft2Wheel),
left3Wheel(RobotMap::chassisLeft3Wheel),
right1Wheel(RobotMap::chassisRight1Wheel),
right2Wheel(RobotMap::chassisRight2Wheel),
right3Wheel(RobotMap::chassisRight3Wheel) {

    right1Wheel->SetInverted(true);

    //TODO:look into follower mode's changes
}

void Chassis::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

        SetDefaultCommand(new TankDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::SetTankDrive(double left, double right) {
  left1Wheel->Set(left);
  left2Wheel->Set(left);
  left3Wheel->Set(left);

  right1Wheel->Set(right);
  right2Wheel->Set(right);
  right3Wheel->Set(right);
}
