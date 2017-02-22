#include "Turret.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "../Commands/SetTurret.h"

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
    p(0.0), i(0.0), d(0.0)
    {
  turretSpinner.Enable();
  turretSpinner.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  turretSpinner.SetControlMode(frc::CANSpeedController::kSpeed);
 // turretSpinner.SetControlMode(frc::CANSpeedController::kPercentVbus);
  turretSpinner.SetPID(p, i, d);
  turretSpinner.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
  turretSpinner.ConfigLimitMode(CANTalon::kLimitMode_SwitchInputsOnly);
}

void Turret::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  defaultCommand = new robovikes::SetTurret(GetTurretPosition());
  SetDefaultCommand(defaultCommand);
  //SetDefaultCommand(new robovikes::SetTurret(0.0));
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
  return turretSpinner.IsRevLimitSwitchClosed();
}

bool Turret::IsRightStopperHit() const{
  return turretSpinner.IsFwdLimitSwitchClosed();
}

void Turret::Calibrate(){
  turretSpinner.SetControlMode(CANTalon::kPercentVbus);
}

void Turret::FinishCalibrate(double newPosition){
  turretSpinner.SetControlMode(CANTalon::kPosition);
  defaultCommand->SetPosition(newPosition);
  SetTurretPosition(newPosition);
}

double Turret::GetTurretVoltage() const{
  return turretSpinner.GetOutputVoltage();
}

double Turret::GetTurretCurrent() const{
  return turretSpinner.GetOutputCurrent();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
