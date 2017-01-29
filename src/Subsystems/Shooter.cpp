#include "Shooter.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/SetShooter.h"

const char Shooter::kSubsystemName[] = "Shooter";

std::shared_ptr<Shooter> Shooter::self;

std::shared_ptr<Shooter> Shooter::getInstance() {
	if (! self) {
		self = std::make_shared<Shooter>();
	}
	return self;
}

Shooter::Shooter() : Subsystem(kSubsystemName),

  FlyWheelTop1(RobotMap::kIDFlyWheelTop1),
	FlyWheelTop2(RobotMap::kIDFlyWheelTop2),
	FlyWheelBottom(RobotMap::kIDFlyWheelBottom)

  {

  FlyWheelTop1.Enable();
  FlyWheelTop1.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);

  FlyWheelTop2.Enable();
  FlyWheelTop2.SetControlMode(frc::CANSpeedController::kFollower);
  FlyWheelTop2.Set(RobotMap::kIDFlyWheelTop1);

  FlyWheelBottom.Enable();
  FlyWheelBottom.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ::SetShooter(0.0));
}

void Shooter::SetShooter(double RPM){

  FlyWheelTop1.Set(RPM);
  FlyWheelBottom.Set(RPM * .75);

}

bool Shooter::IsLeftTurretAlligned() const{
  return FlyWheelTop2.IsFwdLimitSwitchClosed();
}

bool Shooter::IsrightTurretAlligned() const{
  return FlyWheelTop2.IsRevLimitSwitchClosed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
