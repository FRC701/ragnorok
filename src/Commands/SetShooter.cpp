#include "SetShooter.h"
#include "../Subsystems/Shooter.h"

using namespace robovikes;

SetShooter::SetShooter(double speed) :
    mSpeed(speed) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Shooter::getInstance().get());
}

// Called once when the command executes
void SetShooter::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void SetShooter::Execute() {
  Shooter::getInstance()->SetShooter(mSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetShooter::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void SetShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooter::Interrupted() {

}

double SetShooter::GetSpeed() const {
  return mSpeed;
}

void SetShooter::SetSpeed(double speed) {
  mSpeed = speed;
}

