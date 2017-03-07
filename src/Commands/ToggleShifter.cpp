#include "ToggleShifter.h"
#include "Subsystems/Chassis.h"

ToggleShifter::ToggleShifter() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Chassis::getInstance().get());
}

// Called once when the command executes
void ToggleShifter::Initialize() {
  if(Chassis::getInstance()->GetTankDriveCommand()->IsAutoShifterEnabled()){
  	 Chassis::getInstance()->GetTankDriveCommand()->SetAutomaticShifting(false);
  }
  Chassis::ShifterValue value
    = Chassis::getInstance()->IsShifterHigh() ? Chassis::kShifterLow : Chassis::kShifterHigh;
  Chassis::getInstance()->SetShifter(value);
}
