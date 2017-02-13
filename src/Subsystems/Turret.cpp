#include "Turret.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/SetTurret.h"

const char Turret::kSubsystemName[] = "Turret";

std::shared_ptr<Turret> Turret::self;

std::shared_ptr<Turret> Turret::getInstance() {
	if (! self) {
		self = std::shared_ptr<Turret>(new Turret);
	}
	return self;
}

Turret::Turret() : Subsystem(kSubsystemName),
		defaultCommand(nullptr),
    turretSpinner(RobotMap::kIDTurretSpinner),
    p(0.06), i(0.0), d(0.0)
    {
  turretSpinner.Enable();
  turretSpinner.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  turretSpinner.SetControlMode(frc::CANSpeedController::kPosition);
  turretSpinner.SetPID(p, i, d);
}

void Turret::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  defaultCommand = new robovikes::SetTurret(GetTurretPosition());
	SetDefaultCommand(defaultCommand);
}

robovikes::SetTurret* Turret::GetSetPositionCommand(){
	return defaultCommand;
}

void Turret::SetTurret(double speed){

  turretSpinner.Set(speed);
}

void Turret::SetTurretPosition(double position) {
	turretSpinner.SetPosition(position);
}

double Turret::GetTurret() const {
  return turretSpinner.Get();
}

double Turret::GetSetPoint() const {
	return turretSpinner.GetSetpoint();
}

double Turret::GetTurretPosition() const {
  return turretSpinner.GetPosition();
}

bool Turret::IsLeftStopperHit() const{
  return turretSpinner.IsFwdLimitSwitchClosed();
}

bool Turret::IsRightStopperHit() const{
  return turretSpinner.IsRevLimitSwitchClosed();
}

void Turret::Calibrate(){
  turretSpinner.SetControlMode(CANTalon::kPercentVbus);
}

void Turret::FinishCalibrate(double newPosition){
  turretSpinner.SetControlMode(CANTalon::kPosition);
  defaultCommand->SetPosition(newPosition);
  SetTurretPosition(newPosition);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
