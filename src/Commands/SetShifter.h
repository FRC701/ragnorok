#ifndef SetShifter_H
#define SetShifterH

#include "Commands/InstantCommand.h"
#include "../Subsystems/Chassis.h"

class SetShifter : public frc::InstantCommand {
public:
	SetShifter(Chassis::ShifterValue value);
	void Initialize();
private:
	Chassis::ShifterValue mValue;
};

#endif  // SetShifter_H
