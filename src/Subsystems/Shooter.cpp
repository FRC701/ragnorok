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

  flyWheelTop1(RobotMap::kIDTop1FlyWheel),
	flyWheelTop2(RobotMap::kIDTop2FlyWheel),
	flyWheelBottom(RobotMap::kIDBottomFlyWheel)

  {

  flyWheelTop1.Enable();
  flyWheelTop1.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);

  flyWheelTop2.Enable();
  flyWheelTop2.SetControlMode(frc::CANSpeedController::kFollower);
  flyWheelTop2.Set(RobotMap::kIDTop1FlyWheel);

  flyWheelBottom.Enable();
  flyWheelBottom.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ::SetShooter(0.0));
}

void Shooter::SetShooter(double RPM){

  flyWheelTop1.Set(RPM);
  flyWheelBottom.Set(RPM * .75);

}

double Shooter::GetTopShooterRPM() const{
  return flyWheelTop1.GetSpeed();
}

double Shooter::GetBottomShooterRPM() const{
  return flyWheelBottom.GetSpeed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
