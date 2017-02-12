#include "Calibrate.h"
#include "Subsystems/Turret.h"
#include "Subsystems/Chassis.h"

Calibrate::Calibrate() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Turret::getInstance().get());
}

static bool IsAligned() {
  std::shared_ptr<Turret> turret = Turret::getInstance();
  std::shared_ptr<Chassis> chassis = Chassis::getInstance();

  bool isRightStopperHit = turret->IsRightStopperHit();
  bool isLeftStopperHit = turret->IsLeftStopperHit();
  bool is0DegTurretAlligned = chassis->Is0DegTurretAlligned();

  return isRightStopperHit || isLeftStopperHit || is0DegTurretAlligned;
}

double GetHeading() {
  std::shared_ptr<Turret> turret = Turret::getInstance();
  std::shared_ptr<Chassis> chassis = Chassis::getInstance();

  bool isRightStopperHit = turret->IsRightStopperHit();
  bool isLeftStopperHit = turret->IsLeftStopperHit();

  bool isBothMagsHit = (chassis->Is0DegTurretAlligned() && chassis->Is90DegTurretAlligned());

  bool isJustZeroMagHit = (chassis->Is0DegTurretAlligned() && !(chassis->Is90DegTurretAlligned()));

  if(isRightStopperHit){
      return turret->kAtRight;
    }

  else if(isLeftStopperHit){
    return turret->kAtLeft;
  }

  else if(isBothMagsHit) {
    return turret->kAtBothMags;
  }

  else if(isJustZeroMagHit) {
    return turret->kAt0Mag;
  }

  else {
    return turret->GetTurretPosition();
  }

}
// Called just before this Command runs the first time
void Calibrate::Initialize() {
  Turret::getInstance()->Calibrate();
}

// Called repeatedly when this Command is scheduled to run
void Calibrate::Execute() {
  std::shared_ptr<Turret> turret = Turret::getInstance();

  if(IsAligned()) {
    //Do nothing
  }
  else {
    turret->SetTurret(0.5);  //TODO check if this is positive or negative
  }
}

// Make this return true when this Command no longer needs to run execute()
bool Calibrate::IsFinished() {

    return IsAligned();
}

// Called once after isFinished returns true
void Calibrate::End() {
  std::shared_ptr<Turret> turret = Turret::getInstance();
  turret->SetTurretPosition(GetHeading());
  turret->FinishCalibrate();
}

// Called when another command which requires one or more of the same
void Calibrate::Interrupted() {

}
