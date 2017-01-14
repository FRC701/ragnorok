#ifndef SetShooter_H
#define SetShooter_H

#include "Commands/InstantCommand.h"

class SetShooter : public frc::InstantCommand {
public:
	SetShooter(double speed);
	void Initialize();
private:
	double mSpeed;
};

#endif  // SetShooter_H
