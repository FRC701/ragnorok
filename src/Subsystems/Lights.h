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

  enum LightValue{
    kLightOn = Relay::kOn,
    kLightOff = Relay::kOff};

  static std::shared_ptr<Lights> getInstance();

	void InitDefaultCommand();

	void SetGlow(LightValue value);

	bool IsLightOn() const;
};

#endif  // Lights_H
