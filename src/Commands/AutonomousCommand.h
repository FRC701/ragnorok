#ifndef AUTONOMOUS_COMMAND_H
#define AUTONOMOUS_COMMAND_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutonomousCommand: public Command {
public:
   	AutonomousCommand();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
