#include "SetTurret.h"
#include "../Subsystems/Turret.h"

SetTurret::SetTurret(double speed) :
      mSpeed(speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Turret::getInstance().get());
}

// Called just before this Command runs the first time
void SetTurret::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetTurret::Execute() {
  Turret::getInstance()->SetTurret(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetTurret::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetTurret::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetTurret::Interrupted() {

}
