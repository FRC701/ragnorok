#ifndef LightsOn_H
#define LightsOn_H

#include "Commands/Command.h"
#include <Notifier.h>
#include "Timer.h"

class LightsOn : public Command {
public:
	LightsOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetTimeFlashing(double timeFlashing);
private:

	Notifier flash;
	bool flashed;

	Timer timeToFlash;
  double mTimeFlashing;
	bool shouldFlash;

	void Notify();
};

#endif  // LightsOn_H
