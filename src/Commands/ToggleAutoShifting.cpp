#include "ToggleAutoShifting.h"
#include "TankDrive.h"
#include "../Subsystems/Chassis.h"

ToggleAutoShifting::ToggleAutoShifting(bool autoShift)
: mAutoShift(autoShift) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ToggleAutoShifting::Initialize() {
	std::shared_ptr<Chassis> chassis = Chassis::getInstance();
	 mAutoShift =
			chassis->IsShifterHigh() ? Chassis::kShifterLow : Chassis::kShifterHigh;
	chassis->GetTankDriveCommand()->TankDrive(mAutoShift)

}
