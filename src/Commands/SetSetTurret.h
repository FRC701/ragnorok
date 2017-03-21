#ifndef SetSetTurret_H
#define SetSetTurret_H

#include "Commands/InstantCommand.h"

class SetSetTurret : public InstantCommand {
public:
	SetSetTurret(double position);
	void Initialize();

private:
	double position;
};

#endif  // SetSetTurret_H
