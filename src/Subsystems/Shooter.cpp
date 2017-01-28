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
	TopMotor1(RobotMap::kIDFlyWheelTop1),
	TopMotor2(RobotMap::kIDFlyWheelTop2),
	BottomMotor(RobotMap::kIDFlyWheelBottom),
	p(0.06),
	i(0.0001),
	d(0),
	nudge(0)
{
  TopMotor1.Enable();
  TopMotor1.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  TopMotor1.SetControlMode(frc::CANSpeedController::kSpeed);
  TopMotor1.SetPID(p, i, d);
  TopMotor1.SetSensorDirection(false);

  TopMotor2.Enable();
  TopMotor2.SetControlMode(frc::CANSpeedController::kFollower);
  TopMotor2.Set(RobotMap::kIDFlyWheelTop1);

  BottomMotor.Enable();
  BottomMotor.SetControlMode(frc::CANSpeedController::kFollower);
  BottomMotor.Set(RobotMap::kIDFlyWheelTop1);

}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new ::SetShooter(0.0));
 // SetDefaultCommand(new ::SetShooter(Shooter::getInstance()->GetSetPoint()));
}

void Shooter::SetShooter(double speed) {
 /* if (rightMotor.IsEnabled() && speed != 0.0 && GetEncoderVelocity() == 0) {
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
  */
  TopMotor1.Set(speed);
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
  TopMotor1.Disable();
  eStopTimer.Stop();
  eStopTimerStarted = false;
}

double Shooter::GetShooter() const{
	return TopMotor1.Get();
}

double Shooter::GetOutputCurrent() const{
  return TopMotor1.GetOutputCurrent();
}

double Shooter::GetOutputVoltage() const{
  return TopMotor1.GetOutputVoltage();
}

int Shooter::GetEncoderVelocity() const{
  return TopMotor1.GetEncVel();
}

void Shooter::Nudge(double value){
  nudge += value;
}

double Shooter::GetSetPoint() const{
  return TopMotor1.GetSetpoint();
}

double Shooter::GetSpeed() const{
  return TopMotor1.GetSpeed();
}

int Shooter::GetShooterError() const{
  return TopMotor1.GetClosedLoopError();
}

void Shooter::Enable() {
  TopMotor1.Enable();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
