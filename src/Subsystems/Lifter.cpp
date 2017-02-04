#include "Lifter.h"
#include "../RobotMap.h"
#include "CANTalon.h"

const char Lifter::kSubsystemName[] = "Lifter";

std::shared_ptr<Lifter> Lifter::self;

std::shared_ptr<Lifter> Lifter::getInstance() {
	if (! self){
		self = std::make_shared<Lifter>();
	}
	return self;
}

Lifter::Lifter() : Subsystem(kSubsystemName),
  leftClimber(RobotMap::kIDLeftClimber),
  rightClimber(RobotMap::kIDRightClimber) {

  leftClimber.SetInverted(true);
}

void Lifter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Lifter::SetLifter(double speed){
	leftClimber.Set(speed);
	rightClimber.Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
