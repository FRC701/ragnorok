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

  FlyWheelTop1(RobotMap::kIDTop1FlyWheel),
	FlyWheelTop2(RobotMap::kIDTop2FlyWheel),
	FlyWheelBottom(RobotMap::kIDBottomFlyWheel)

  {

  FlyWheelTop1.Enable();
  FlyWheelTop1.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);

  FlyWheelTop2.Enable();
  FlyWheelTop2.SetControlMode(frc::CANSpeedController::kFollower);
  FlyWheelTop2.Set(RobotMap::kIDTop1FlyWheel);

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

double Shooter::GetTopShooterRPM() const{
  return FlyWheelTop1.GetSpeed();
}

double Shooter::GetBottomShooterRPM() const{
  return FlyWheelBottom.GetSpeed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
