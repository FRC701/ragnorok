#include "Shooter.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/SetShooter.h"
#include "SmartDashboard/SmartDashboard.h"


const char Shooter::kSubsystemName[] = "Shooter";

std::shared_ptr<Shooter> Shooter::self;

std::shared_ptr<Shooter> Shooter::getInstance() {
	if (! self) {
		self = std::make_shared<Shooter>();
	}
	return self;
}

Shooter::Shooter() : Subsystem(kSubsystemName),


	rightMotor(RobotMap::kIDShooterRight),
	leftMotor(RobotMap::kIDShooterLeft)
	{

  p = 0.005;
  i = 0;
  d = 0;
	leftMotor.SetInverted(false);
  leftMotor.SetControlMode(frc::CANSpeedController::kPercentVbus);
  //leftMotor.Set(RobotMap::kIDShooterRight);
	rightMotor.SetInverted(false);
  rightMotor.SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
  rightMotor.SetControlMode(frc::CANSpeedController::kSpeed);
  rightMotor.SetPID(p, i, d);
  nudge = 0;


}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ::SetShooter(0.0));
}

void Shooter::SetShooter(double speed){

  rightMotor.Set(speed + nudge);
  leftMotor.Set(1);

}

double Shooter::GetShooter(){

	return leftMotor.Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
