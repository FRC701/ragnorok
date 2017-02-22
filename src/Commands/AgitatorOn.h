#ifndef AgitatorOn_H
#define AgitatorOn_H

#include "Commands/InstantCommand.h"

class AgitatorOn : public InstantCommand {
public:
	AgitatorOn();
	void Initialize();

protected:
	bool IsFinished() override;
};

#endif  // AgitatorOn_H
