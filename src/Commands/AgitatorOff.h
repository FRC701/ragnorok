#ifndef Agitator_OffH
#define AgitatorOff_H

#include "Commands/InstantCommand.h"
#include "Subsystems/Magazine.h"

class AgitatorOff : public InstantCommand {
public:
	AgitatorOff();
	void Initialize();
};

#endif  // AgitatorOff_H
