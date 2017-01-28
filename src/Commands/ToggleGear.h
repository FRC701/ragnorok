#ifndef ToggleGear_H
#define ToggleGear_H

#include "Commands/Command.h"

class ToggleGear : public frc::Command {
public:
	ToggleGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleGear_H
