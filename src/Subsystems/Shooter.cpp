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
  defaultCommand(0.0),
  top1FlyWheel(RobotMap::kIDTop1FlyWheel),
  top2FlyWheel(RobotMap::kIDTop2FlyWheel),
  bottomFlyWheel(RobotMap::kIDBottomFlyWheel),
  p(0.06), i(0.0001), d(0)
{
  top1FlyWheel.Enable();
  top1FlyWheel.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  top1FlyWheel.SetControlMode(frc::CANSpeedController::kSpeed);
  top1FlyWheel.SetPID(p, i, d);
  top1FlyWheel.SetSensorDirection(false);
    
  top2FlyWheel.Enable();
  top2FlyWheel.SetControlMode(frc::CANSpeedController::kFollower);
  top2FlyWheel.Set(RobotMap::kIDTop2FlyWheel);
  
  bottomFlyWheel.Enable();
  bottomFlyWheel.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
}

void Shooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(&defaultCommand);
}

robovikes::SetShooter* Shooter::GetSetShooterCommand()
{
  return &defaultCommand;
}

void Shooter::SetShooter(double RPM){
  top1FlyWheel.Set(RPM);
  bottomFlyWheel.Set(RPM * .75);
}

double Shooter::GetOutputCurrent() const {
  return top1FlyWheel.GetOutputCurrent();
}

double Shooter::GetOutputVoltage() const {
  return top1FlyWheel.GetOutputVoltage();
}

int Shooter::GetEncoderVelocity() const {
  return top1FlyWheel.GetEncVel();
}

double Shooter::GetSetPoint() const {
  return top1FlyWheel.GetSetpoint();
}

 int Shooter::GetShooterError() const {
  return top1FlyWheel.GetClosedLoopError();
}
double Shooter::GetTopShooterRPM() const{
  return top1FlyWheel.GetSpeed();
}

double Shooter::GetBottomShooterRPM() const{
  return bottomFlyWheel.GetSpeed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
