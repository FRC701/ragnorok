#ifndef ToggleAutoShifting_H
#define ToggleAutoShifting_H

#include "Commands/InstantCommand.h"

class ToggleAutoShifting : public InstantCommand {
public:
	ToggleAutoShifting();
	void Initialize();

private:
	bool mAutoShift;
};

#endif  // ToggleAutoShifting_H
