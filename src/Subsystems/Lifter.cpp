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

Lifter::Lifter() : Subsystem(kSubsystemName) {

}

void Lifter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
