#include "Lights.h"
#include "../RobotMap.h"
#include "Commands/LightsOn.h"

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
  SetGlow(Relay::kOn);
}

void Lights::InitDefaultCommand() {
	// Set the default command for a subsystem here.
  SetDefaultCommand(new LightsOn);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lights::SetGlow(Relay::Value value) {
  glow.Set(static_cast<Relay::Value>(value));
}

bool Lights::IsGlowOn() {
  return glow.Get() == Relay::kOn;
}
void Lights::ToggleGlow() {
  Relay::Value value
    = IsGlowOn() ? Relay::kOff: Relay::kOn;
  SetGlow(value);
}
