#ifndef LightsOn_H
#define LightsOn_H

#include "Commands/Command.h"
#include <Notifier.h>

class LightsOn : public Command {
public:
	LightsOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Notifier flash;
	bool flashed;

	void Notify();
};

#endif  // LightsOn_H
