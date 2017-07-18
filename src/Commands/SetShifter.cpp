#include <Commands/SetShifter.h>

SetShifter::SetShifter(Chassis::ShifterValue value) :
  mValue(value) {
	// Use Requires() here to declare subsystem dependencies
  Requires(Chassis::getInstance().get());
}

// Called once when the command executes
void SetShifter::Initialize() {
  Chassis::getInstance()->SetShifter(mValue);
}
