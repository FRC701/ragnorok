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
  defaultCommand(nullptr),
  top1FlyWheel(RobotMap::kIDTop1FlyWheel),
  top2FlyWheel(RobotMap::kIDTop2FlyWheel),
  bottomFlyWheel(RobotMap::kIDBottomFlyWheel),
  Tp(0.08), Ti(0.0001), Td(0),
  Bp(0.14), Bi(0.0002), Bd(0)
{
  top1FlyWheel.Enable();
  top1FlyWheel.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  top1FlyWheel.SetControlMode(frc::CANSpeedController::kSpeed);
  top1FlyWheel.SetPID(Tp, Ti, Td);
  top1FlyWheel.SetSensorDirection(false);
    
  top2FlyWheel.Enable();
  top2FlyWheel.SetControlMode(frc::CANSpeedController::kFollower);
  top2FlyWheel.Set(RobotMap::kIDTop1FlyWheel);
  
  bottomFlyWheel.Enable();
  bottomFlyWheel.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  bottomFlyWheel.SetControlMode(frc::CANSpeedController::kSpeed);
  bottomFlyWheel.SetPID(Bp, Bi, Bd);
  bottomFlyWheel.SetSensorDirection(true);
}

void Shooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  defaultCommand = new robovikes::SetShooter(0.0),
  SetDefaultCommand(defaultCommand);
}

robovikes::SetShooter* Shooter::GetSetShooterCommand()
{
  return defaultCommand;
}

void Shooter::SetShooter(double RPM){
  top1FlyWheel.Set(RPM);
  bottomFlyWheel.Set(-RPM);
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
