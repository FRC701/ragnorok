#include "ToggleShifter.h"
#include "Subsystems/Chassis.h"

ToggleShifter::ToggleShifter() {
  Requires(Chassis::getInstance().get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void ToggleShifter::Initialize() {
  Chassis::ShifterValue value
    = Chassis::getInstance()->IsShifterHigh() ? Chassis::kShifterLow : Chassis::kShifterHigh;
  Chassis::getInstance()->SetShifter(value);
}
