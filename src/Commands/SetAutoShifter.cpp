#include "SetAutoShifter.h"

SetAutoShifter::SetAutoShifter(Chassis::AutoShifterValue value) :
  mValue(value) {
	// Use Requires() here to declare subsystem dependencies
  Requires(Chassis::getInstance().get());
}

// Called once when the command executes
void SetAutoShifter::Initialize() {
  Chassis::getInstance()->GetTankDriveCommand()->SetAutomaticShifting(mValue);
}
