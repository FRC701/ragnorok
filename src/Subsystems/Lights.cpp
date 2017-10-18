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
  //glow(RobotMap::kIDRelay)
		glow(RobotMap::kIDDigitalOutput)
    {
  SetGlow(LightsValue::kLightsOn);
}

void Lights::InitDefaultCommand() {
	// Set the default command for a subsystem here.
  SetDefaultCommand(new LightsOn);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lights::SetGlow(LightsValue value) {
  glow.Set(value);
}

bool Lights::IsGlowOn() {
  return glow.Get() == LightsValue::kLightsOn;
}
void Lights::ToggleGlow() {
  LightsValue value
    = IsGlowOn() ? LightsValue::kLightsOff: LightsValue::kLightsOn;
  SetGlow(value);
}
