#include "Turret.h"
#include "../RobotMap.h"
#include "CANTalon.h"

const char Turret::kSubsystemName[] = "Turret";

std::shared_ptr<Turret> Turret::self;

std::shared_ptr<Turret> Turret::getInstance() {
	if (! self) {
		self = std::make_shared<Turret>();
	}
	return self;
}

Turret::Turret() : Subsystem(kSubsystemName) {

}

void Turret::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
