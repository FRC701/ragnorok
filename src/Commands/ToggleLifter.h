#ifndef ToggleLifter_H
#define ToggleLifter_H

#include "Commands/Command.h"

class ToggleLifter : public frc::Command {
public:
	ToggleLifter(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double mSpeed;

	bool turnOn;
};

#endif  // ToggleLifter_H
