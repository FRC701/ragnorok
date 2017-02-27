#ifndef LightDefaultBlink_H
#define LightDefaultBlink_H

#include "Commands/Command.h"
#include "Notifier.h"

class LightDefaultBlink : public Command {
public:
	LightDefaultBlink(double seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SecondsToWait(double secondsToWait);
	void ToggleLights();
private:
	double mSeconds;
	Notifier notifier;
};

#endif  // LightDefaultBlink_H
