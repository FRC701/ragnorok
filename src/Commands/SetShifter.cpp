#include <Commands/SetShifter.h>

SetShifter::SetShifter(Chassis::ShifterValue value) :
  mValue(value) {
 Requires(Chassis::getInstance().get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void SetShifter::Initialize() {
  Chassis::getInstance()->SetShifter(mValue);
}
