#ifndef ConveyorControl_H
#define ConveyorControl_H

#include "Commands/Command.h"

class ConveyorControl : public frc::Command {
public:
  ConveyorControl(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mSpeed;
};

#endif  // ConveyorControl_H
