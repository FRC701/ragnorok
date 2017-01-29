#ifndef SetIntake_H
#define SetIntake_H

#include "Commands/Command.h"

class SetIntake : public frc::Command {
public:
	SetIntake(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double mSpeed;
};

#endif  // SetIntake_H
