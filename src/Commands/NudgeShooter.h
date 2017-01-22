#ifndef NudgeShooter_H
#define NudgeShooter_H

#include "Commands/Command.h"

class NudgeShooter : public frc::Command {
public:
	NudgeShooter(double nudge);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double mNudge;
	double speed;
};

#endif  // NudgeShooter_H
