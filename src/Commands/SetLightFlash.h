#ifndef SetLightFlash_H
#define SetLightFlash_H

#include "Commands/InstantCommand.h"

class SetLightFlash : public frc::InstantCommand {
public:
	SetLightFlash(double timeFlashing);
	void Initialize();

private:

	double mTimeFlashing;
};

#endif  // SetLightFlash_H
