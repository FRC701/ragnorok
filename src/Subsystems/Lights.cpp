#include "Lights.h"
#include "../RobotMap.h"

const char Lights::kSubsystemName[] = "Lights";

std::shared_ptr<Lights> Lights::self;

std::shared_ptr<Lights> Lights::getInstance() {
  if(! self) {
    self = std::shared_ptr<Lights>(new Lights);
  }
  return self;
}

Lights::Lights() : Subsystem(kSubsystemName),
  glow(RobotMap::kIDRelay)
    {
  SetGlow();
}

void Lights::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lights::SetGlow() {
  glow.Set(Relay::kOn);
}
