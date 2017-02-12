#ifndef SetLifter_H
#define SetLifter_H

#include "Commands/Command.h"

class SetLifter : public frc::Command {
public:
	SetLifter(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double mSpeed;
};

#endif  // SetLifter_H
