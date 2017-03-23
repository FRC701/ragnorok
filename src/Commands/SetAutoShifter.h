#ifndef SetAutoShifter_H
#define SetAutoShifter_H

#include "Commands/InstantCommand.h"
#include "../Subsystems/Chassis.h"

class SetAutoShifter : public InstantCommand {
public:
	SetAutoShifter(Chassis::AutoShifterValue value);
	void Initialize();
private:
	Chassis::AutoShifterValue mValue;
};

#endif  // SetAutoShifter_H
