#include <Commands/AgitatorOn.h>
#include "Subsystems/Magazine.h"

AgitatorOn::AgitatorOn() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Magazine::getInstance().get());
}
// Called just before this Command runs the first time
void AgitatorOn::Initialize() {
  Magazine::getInstance()->StartAgitator(1.0);
}

bool AgitatorOn::IsFinished() {
	return false;
}
