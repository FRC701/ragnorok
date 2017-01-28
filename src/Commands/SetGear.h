#ifndef SetGear_H
#define SetGear_H

#include "Commands/Command.h"
#include "Subsystems/GearPickup.h"

class SetGear : public frc::Command {
public:
  SetGear(GearPickup::PickupValue value);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	GearPickup::PickupValue mValue;
};

#endif  // SetGear_H
