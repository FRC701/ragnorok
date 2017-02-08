#include "ToggleAutoShifting.h"
#include "TankDrive.h"
#include "../Subsystems/Chassis.h"

ToggleAutoShifting::ToggleAutoShifting()
: mAutoShift(nullptr) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleAutoShifting::Initialize() {
	std::shared_ptr<Chassis> chassis = Chassis::getInstance();

	mAutoShift =
	    chassis->IsAutoShifterOn() ? Chassis::kAutoShiftOff : Chassis::kAutoShiftOn;
	    chassis->defaultCommand->SetAutomaticShifting(mAutoShift);
	    SmartDashboard::PutNumber("AutoShifter", mAutoShift);


}
