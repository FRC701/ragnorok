#include "SetAutoShifter.h"

SetAutoShifter::SetAutoShifter(Chassis::AutoShifterValue value) :
  mValue(value) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Chassis::getInstance().get());
}

// Called once when the command executes
void SetAutoShifter::Initialize() {
  Chassis::getInstance()->GetTankDriveCommand()->SetAutomaticShifting(mValue);
}
