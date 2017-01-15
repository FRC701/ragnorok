#ifndef SetTurret_H
#define SetTurret_H

#include "Commands/Command.h"

class SetTurret : public frc::Command {
public:
	SetTurret(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double mSpeed;
};

#endif  // SetTurret_H
