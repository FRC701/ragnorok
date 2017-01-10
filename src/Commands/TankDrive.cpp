#include "Robot.h"
#include "TankDrive.h"
#include "../Subsystems/Chassis.h"

TankDrive::TankDrive(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
	Requires(Chassis::getInstance().get());
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	double left = Robot::oi->getDriverLeftYAxis();
	double right = Robot::oi->getDriverRightYAxis();

	std::shared_ptr<Chassis> chassis = Chassis::getInstance();

	chassis->SetTankDrive(left, right);
	chassis->GetCurrentCommand();
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void TankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {

}
