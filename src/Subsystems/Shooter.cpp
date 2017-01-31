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

  flyWheel1Top(RobotMap::kIDTop1FlyWheel),
	flyWheel2Top(RobotMap::kIDTop2FlyWheel),
	flyWheelBottom(RobotMap::kIDBottomFlyWheel)

  {

	flyWheel1Top.Enable();
	flyWheel1Top.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);

	flyWheel2Top.Enable();
	flyWheel2Top.SetControlMode(frc::CANSpeedController::kFollower);
	flyWheel2Top.Set(RobotMap::kIDTop1FlyWheel);

  flyWheelBottom.Enable();
  flyWheelBottom.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ::SetShooter(0.0));
}

void Shooter::SetShooter(double RPM){

	flyWheel1Top.Set(RPM);
  flyWheelBottom.Set(RPM * .75);

}

double Shooter::GetTopShooterRPM() const{
  return flyWheel1Top.GetSpeed();
}

double Shooter::GetBottomShooterRPM() const{
  return flyWheelBottom.GetSpeed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
