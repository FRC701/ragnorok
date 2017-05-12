#include "TankDrive.h"
#include "ToggleAutoShifting.h"
#include "../Subsystems/Chassis.h"

ToggleAutoShifting::ToggleAutoShifting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleAutoShifting::Initialize() {
	std::shared_ptr<Chassis> chassis = Chassis::getInstance();

bool mAutoShift =
	    chassis->IsAutoShifterOn() ? Chassis::kAutoShiftOff : Chassis::kAutoShiftOn;
	    chassis->GetTankDriveCommand()->SetAutomaticShifting(mAutoShift);
}
