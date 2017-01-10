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

	kID1(RobotMap::kID1),
	kID2(RobotMap::kID2){

	kID2.SetInverted(true);

}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DefaultShooter());
}

void Shooter::SetShooter(double speed){

	kID1.Set(speed);
	kID2.Set(speed);
}

double Shooter::GetShooterspeed(){

	return kID1.Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
