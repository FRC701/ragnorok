#ifndef SetConveyor_H
#define SetConveyor_H

#include "Commands/Command.h"

class SetConveyor : public frc::Command {
public:
  SetConveyor(double conveyorSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double mConveyorSpeed;
};

#endif  // SetConveyor_H
