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
		defaultCommand(nullptr),
  //glow(RobotMap::kIDRelay)
		glow(RobotMap::kIDDigitalOutput),
		arduinoGlow(RobotMap::kIDArduinoGlow)
    {

  SetGlow(LightsValue::kLightsOn);

}

void Lights::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	defaultCommand = new LightsOn();
  SetDefaultCommand(defaultCommand);
}

LightsOn* Lights::GetLightsOnCommand() {
	return defaultCommand;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lights::SetGlow(LightsValue value) {
  glow.Set(value);
  arduinoGlow.Set(value);
}

bool Lights::IsGlowOn() {
  return glow.Get() == LightsValue::kLightsOn;
}
void Lights::ToggleGlow() {
  LightsValue value
    = IsGlowOn() ? LightsValue::kLightsOff: LightsValue::kLightsOn;
  SetGlow(value);
}
