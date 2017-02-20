#ifndef SetGear_H
#define SetGear_H

#include "Commands/InstantCommand.h"
#include "Subsystems/GearPickup.h"

class SetGear : public frc::InstantCommand {
public:
  SetGear(GearPickup::PickupValue value);
	void Initialize();
private:
	GearPickup::PickupValue mValue;
};

#endif  // SetGear_H
