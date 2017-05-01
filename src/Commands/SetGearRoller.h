#ifndef SetGearRoller_H
#define SetGearRoller_H

#include "Commands/Command.h"
#include "Timer.h"

class SetGearRoller : public Command {
public:
	SetGearRoller(double rollerSpeedRPM);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double rollerSpeedRPM;
	Timer timeout;

};

#endif  // SetGearRoller_H
