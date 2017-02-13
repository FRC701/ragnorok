#include "Lifter.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "../Commands/SetLifter.h"

const char Lifter::kSubsystemName[] = "Lifter";

std::shared_ptr<Lifter> Lifter::self;

std::shared_ptr<Lifter> Lifter::getInstance() {
	if (! self){
		self = std::shared_ptr<Lifter>(new Lifter);
	}
	return self;
}

Lifter::Lifter() : Subsystem(kSubsystemName),
  leftClimber(RobotMap::kIDLeftClimber),
  rightClimber(RobotMap::kIDRightClimber) {

  SetBrake();

  leftClimber.SetInverted(true);
}

void Lifter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
 SetDefaultCommand(new ::SetLifter(0.0));
}

void Lifter::SetLifter(double speed){
	leftClimber.Set(speed);
	rightClimber.Set(speed);
}

void Lifter::SetBrake() {
  leftClimber.Set(CANTalon::kNeutralMode_Brake);
  rightClimber.Set(CANTalon::kNeutralMode_Brake);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
