#ifndef GearPickup_H
#define GearPickup_H
#include <DoubleSolenoid.h>
#include <Commands/Subsystem.h>
#include "CANTalon.h"

class GearPickup : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<GearPickup> self;

  CANTalon roller;
  DoubleSolenoid actuator;

public:

  enum PickupValue{kGearUp = DoubleSolenoid::kForward,kGearDown = DoubleSolenoid::kReverse};
//TODO Check this value when robot is done
  static std::shared_ptr<GearPickup> getInstance();

	GearPickup();

	void InitDefaultCommand();
	void SetGear(PickupValue value);

	bool IsGearUp() const;
	bool IsGearAlligned() const;

	double GetGearIntakeRPM() const;
};

#endif  // GearPickup_H
