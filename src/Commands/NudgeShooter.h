#ifndef NudgeShooter_H
#define NudgeShooter_H

#include "Commands/InstantCommand.h"

class NudgeShooter : public InstantCommand {
  double mNudge;
public:
	NudgeShooter(double nudge);
	void Initialize();
};

#endif  // NudgeShooter_H
