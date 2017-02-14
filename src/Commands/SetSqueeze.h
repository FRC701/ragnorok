#ifndef SetSqueeze_H
#define SetSqueeze_H

#include "Commands/InstantCommand.h"
#include "Subsystems/GearPickup.h"

class SetSqueeze : public InstantCommand {
public:
	SetSqueeze(GearPickup::SqueezeValue value);
	void Initialize();
private:
	GearPickup::SqueezeValue mValue;
};

#endif  // SetSqueeze_H
