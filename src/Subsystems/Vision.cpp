#include "Vision.h"
#include "../RobotMap.h"
#include "CANTalon.h"

const char Vision::kSubsystemName[] = "Vision";

std::shared_ptr<Vision> Vision::self;

std::shared_ptr<Vision> Vision::getInstance() {
	if (! self) {
		self = std::shared_ptr<Vision>(new Vision);
	}
	return self;
}

Vision::Vision() : Subsystem(kSubsystemName) {

}

void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
