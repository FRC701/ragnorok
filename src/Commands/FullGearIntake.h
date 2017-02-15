#ifndef FullGearIntake_H
#define FullGearIntake_H

#include <Commands/CommandGroup.h>

class FullGearIntake : public CommandGroup {
public:
	FullGearIntake();
	bool IsGearUp() const;
};

#endif  // FullGearIntake_H
