#ifndef SetIntake_H
#define SetIntake_H

#include "../CommandBase.h"

class SetIntake : public CommandBase {
public:
	SetIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetIntake_H
