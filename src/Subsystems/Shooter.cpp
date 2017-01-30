#include "Shooter.h"
#include "../RobotMap.h"
#include "Commands/SetShooter.h"
#include "SmartDashboard/SmartDashboard.h"

const char Shooter::kSubsystemName[] = "Shooter";

std::shared_ptr<Shooter> Shooter::self;

std::shared_ptr<Shooter> Shooter::getInstance() {
  if (! self) {
    self = std::shared_ptr<Shooter>(new Shooter());
  }
  return self;
}

Shooter::Shooter() : Subsystem(kSubsystemName),
  flyWheelTop1(RobotMap::kIDTop1FlyWheel),
  flyWheelTop2(RobotMap::kIDTop2FlyWheel),
  flyWheelBottom(RobotMap::kIDBottomFlyWheel),
  p(0.06), i(0.0001), d(0),
  nudge(0)
{
  flyWheelTop1.Enable();
  flyWheelTop1.SetInverted(true);
  flyWheelTop1.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  flyWheelTop1.SetControlMode(frc::CANSpeedController::kSpeed);
  flyWheelTop1.SetPID(p, i, d);
  flyWheelTop1.SetSensorDirection(false);

  flyWheelTop2.Enable();
  flyWheelTop2.SetControlMode(frc::CANSpeedController::kFollower);
  flyWheelTop2.Set(RobotMap::kIDTop2FlyWheel);
  flyWheelTop2.SetClosedLoopOutputDirection(true);

  flyWheelBottom.Enable();
  flyWheelBottom.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new ::SetShooter(0.0));
}

void Shooter::SetShooter(double speed) {
  flyWheelTop1.Set(speed);
}

double Shooter::GetShooter() const {
  return flyWheelTop1.Get();
}

double Shooter::GetOutputCurrent() const {
  return flyWheelTop1.GetOutputCurrent();
}

double Shooter::GetOutputVoltage() const {
  return flyWheelTop1.GetOutputVoltage();
}

int Shooter::GetEncoderVelocity() const {
  return flyWheelTop1.GetEncVel();
}

double Shooter::GetSetPoint() const {
  return flyWheelTop1.GetSetpoint();
}

double Shooter::GetSpeed() const {
  return flyWheelTop1.GetSpeed();
}

int Shooter::GetShooterError() const {
  return flyWheelTop1.GetClosedLoopError();
}

void Shooter::Enable() {
  flyWheelTop1.Enable();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
