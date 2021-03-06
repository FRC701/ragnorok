#ifndef Lights_H
#define Lights_H

#include <Commands/Subsystem.h>
#include <Relay.h>

class Lights : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Lights> self;
  Lights();

  Relay glow;
public:

  static std::shared_ptr<Lights> getInstance();

	void InitDefaultCommand();

	void SetGlow(Relay::Value value);
	void ToggleGlow();

	bool IsGlowOn();

};

#endif  // Lights_H
