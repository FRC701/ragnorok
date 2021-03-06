#include "Calibrate.h"
#include "Subsystems/Turret.h"
#include "Subsystems/Chassis.h"

Calibrate::Calibrate() {
	// Use Requires() here to declare subsystem dependencies
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

  bool isLeftStopperHit = turret->IsLeftStopperHit();
  bool isRightStopperHit = turret->IsRightStopperHit();

  bool isBothMagsHit = (chassis->Is0DegTurretAlligned() && chassis->Is90DegTurretAlligned());

  bool isJustZeroMagHit = (chassis->Is0DegTurretAlligned() && !(chassis->Is90DegTurretAlligned()));

  if(isLeftStopperHit){
      return turret->kAtLeft;
  }

  else if(isRightStopperHit){
    return turret->kAtRight;
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
    turret->SetTurret(0.25);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool Calibrate::IsFinished() {
    return IsAligned();
}

// Called once after isFinished returns true
void Calibrate::End() {
  std::shared_ptr<Turret> turret = Turret::getInstance();
  turret->FinishCalibrate(GetHeading());
}

// Called when another command which requires one or more of the same
void Calibrate::Interrupted() {

}
