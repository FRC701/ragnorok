#ifndef StopShooter_H
#define StopShooter_H

#include "Commands/InstantCommand.h"

class StopShooter : public InstantCommand {
public:
	StopShooter();
	void Initialize();
};

#endif  // StopShooter_H
