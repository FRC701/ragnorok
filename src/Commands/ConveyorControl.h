#ifndef ConveyorControl_H
#define ConveyorControl_H

#include "Commands/Command.h"

class ConveyorControl : public frc::Command {
public:
  ConveyorControl(double conveyorSpeed, double moverSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mConveyorSpeed;
	double mMoverSpeed;
};

#endif  // ConveyorControl_H
