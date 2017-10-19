#ifndef Lights_H
#define Lights_H

#include <Commands/Subsystem.h>
#include <Relay.h>
#include "Commands/LightsOn.h"
#include <DigitalOutput.h>

class Lights : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Lights> self;



  Lights();

  LightsOn* defaultCommand;

  //Relay glow;
  DigitalOutput glow;
public:



  enum LightsValue{kLightsOn = true, kLightsOff = false};

  static std::shared_ptr<Lights> getInstance();

  LightsOn* GetLightsOnCommand();

	void InitDefaultCommand();

	void SetGlow(LightsValue value);
	void ToggleGlow();

	bool IsGlowOn();

};

#endif  // Lights_H
