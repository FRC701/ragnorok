#ifndef GearPickup_H
#define GearPickup_H
#include <DoubleSolenoid.h>
#include <Commands/Subsystem.h>

class GearPickup : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<GearPickup> self;

  DoubleSolenoid (Pickup);


public:
  static std::shared_ptr<GearPickup> getInstance();

	GearPickup();
	void InitDefaultCommand();
};

#endif  // GearPickup_H
