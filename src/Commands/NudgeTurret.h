#ifndef NudgeTurret_H
#define NudgeTurret_H

#include "Commands/InstantCommand.h"

class NudgeTurret : public InstantCommand {
public:
	NudgeTurret(double nudge);
	void Initialize();

private:
	double mNudge;
};

#endif  // NudgeTurret_H
