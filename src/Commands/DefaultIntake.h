#ifndef DefaultIntake_H
#define DefaultIntake_H

#include "../CommandBase.h"

class DefaultIntake : public CommandBase {
public:
	DefaultIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DefaultIntake_H
