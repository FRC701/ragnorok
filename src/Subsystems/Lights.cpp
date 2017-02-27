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
  SetGlow(kLightOn);
}

void Lights::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lights::SetGlow(LightValue value) {
  glow.Set(static_cast<Relay::Value>(value));
}

bool Lights::IsLightOn() const{
  return glow.Get() == static_cast<Relay::Value>(kLightOn);
}
