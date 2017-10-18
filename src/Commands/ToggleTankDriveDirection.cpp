#include "TankDrive.h"
#include "ToggleTankDriveDirection.h"
#include "../Subsystems/Chassis.h"

ToggleTankDriveDirection::ToggleTankDriveDirection() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void ToggleTankDriveDirection::Initialize() {
	std::shared_ptr<Chassis> chassis = Chassis::getInstance();

bool mTankDriveDirection =
      chassis->isDriveDirectionReversed() ? Chassis::kDriveDirectionForward : Chassis::kDriveDirectionReversed;
      chassis->GetTankDriveCommand()->SetTankDriveDirection(mTankDriveDirection);

}
