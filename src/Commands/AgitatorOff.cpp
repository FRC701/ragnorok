#include "AgitatorOff.h"

AgitatorOff::AgitatorOff() {
	// Use Requires() here to declare subsystem dependencies
  Requires(Magazine::getInstance().get());
}

// Called just before this Command runs the first time
void AgitatorOff::Initialize() {
	Magazine::getInstance()->StopAgitator();
}
