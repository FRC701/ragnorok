#ifndef ToggleTankDriveDirection_H
#define ToggleTankDriveDirection_H

#include "Commands/InstantCommand.h"

class ToggleTankDriveDirection : public InstantCommand {
public:
	ToggleTankDriveDirection();
	void Initialize();
};

#endif  // ToggleTankDriveDirection_H
