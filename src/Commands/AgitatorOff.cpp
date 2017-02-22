#include "AgitatorOff.h"

AgitatorOff::AgitatorOff() {
	Requires(Magazine::getInstance().get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AgitatorOff::Initialize() {
	Magazine::getInstance()->StopAgitator();
}
