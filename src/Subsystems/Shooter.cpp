#include "Shooter.h"
#include "../RobotMap.h"
#include "Commands/SetShooter.h"
#include "SmartDashboard/SmartDashboard.h"

const char Shooter::kSubsystemName[] = "Shooter";

std::shared_ptr<Shooter> Shooter::self;

std::shared_ptr<Shooter> Shooter::getInstance() {
	if (! self) {
		self = std::make_shared<Shooter>();
	}
	return self;
}

Shooter::Shooter() : Subsystem(kSubsystemName),
  eStopTimer(),
  eStopTimerStarted(false),
	rightMotor(RobotMap::kIDShooterRight),
	leftMotor(RobotMap::kIDShooterLeft),
	p(0.05),
	i(0),
	d(0),
	nudge(0)
{
  rightMotor.SetInverted(false);
  rightMotor.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  rightMotor.SetControlMode(frc::CANSpeedController::kSpeed);
  rightMotor.SetPID(p, i, d);
  rightMotor.SetSensorDirection(true);

  leftMotor.SetInverted(false);
  leftMotor.SetControlMode(frc::CANSpeedController::kFollower);
  leftMotor.Set(RobotMap::kIDShooterRight);
  leftMotor.SetClosedLoopOutputDirection(true);
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ::SetShooter(0.0));
}

void Shooter::SetShooter(double speed) {
  if (rightMotor.IsEnabled() && speed != 0.0 && GetEncoderVelocity() == 0) {
    if (checkEmergencyStop()) {
      emergencyStop();
    } else {
      rightMotor.Set(speed + nudge);
    }
  } else {
    eStopTimer.Stop();
    eStopTimerStarted = false;
    rightMotor.Set(speed + nudge);
  }
}

bool Shooter::checkEmergencyStop() {
  if (eStopTimerStarted) {
    return eStopTimer.HasPeriodPassed(0.25);
  }

  eStopTimer.Start();
  eStopTimerStarted = true;
  return false;
}

void Shooter::emergencyStop() {
  this->GetCurrentCommand()->Cancel();
  rightMotor.Disable();
  eStopTimer.Stop();
  eStopTimerStarted = false;
}

double Shooter::GetShooter() const{
	return rightMotor.Get();
}

double Shooter::GetOutputCurrent() const{
  return rightMotor.GetOutputCurrent();
}

double Shooter::GetOutputVoltage() const{
  return rightMotor.GetOutputVoltage();
}

int Shooter::GetEncoderVelocity() const{
  return rightMotor.GetEncVel();
}

void Shooter::Nudge(double value){
  nudge += value;
}

void Shooter::Enable() {
  rightMotor.Enable();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
