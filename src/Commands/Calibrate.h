#ifndef Calibrate_H
#define Calibrate_H

#include "Commands/Command.h"
#include "Subsystems/Turret.h"

class Calibrate : public Command {
public:
	Calibrate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:

};

#endif  // Calibrate_H
