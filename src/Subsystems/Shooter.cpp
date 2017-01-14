#include "Shooter.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/DefaultShooter.h"

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

	leftMotor.SetInverted(true);

}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DefaultShooter());
}

void Shooter::SetShooter(double speed){

  rightMotor.Set(speed);
  leftMotor.Set(speed);

}

double Shooter::GetShooter(){

	return leftMotor.Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
