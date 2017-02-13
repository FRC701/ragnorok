#include "CANTalon.h"
#include "LiveWindow/LiveWindow.h"
#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"
#include "DoubleSolenoid.h"

const char Chassis::kSubsystemName[] = "Chassis";

std::shared_ptr<Chassis> Chassis::self;

std::shared_ptr<Chassis> Chassis::getInstance() {
  if (! self) {
     self = std::shared_ptr<Chassis>(new Chassis);
  }
  return self;
}


Chassis::Chassis() : Subsystem(kSubsystemName),
	defaultCommand(nullptr),
  right1Wheel(RobotMap::kIDRight1Wheel),
  right2Wheel(RobotMap::kIDRight2Wheel),
  left1Wheel(RobotMap::kIDLeft1Wheel),
  left2Wheel(RobotMap::kIDLeft2Wheel),
  shifter(RobotMap::kIDShitftingForward, RobotMap::kIDShitftingReverse)
  {

  frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

  lw->AddActuator(kSubsystemName , "Right1Wheel", right1Wheel);
  lw->AddActuator(kSubsystemName , "Right2Wheel", right2Wheel);
  lw->AddActuator(kSubsystemName , "Left1Wheel", left1Wheel);
  lw->AddActuator(kSubsystemName , "Left2Wheel", left2Wheel);

  right1Wheel.SetInverted(true);
  right1Wheel.SetFeedbackDevice(CANTalon::QuadEncoder);
  right1Wheel.ConfigEncoderCodesPerRev(128);

  left1Wheel.SetFeedbackDevice(CANTalon::QuadEncoder);
  left1Wheel.ConfigEncoderCodesPerRev(128);

  right2Wheel.SetControlMode(CANTalon::kFollower);
  right2Wheel.Set(RobotMap::kIDRight1Wheel);

  left2Wheel.SetControlMode(CANTalon::kFollower);
  left2Wheel.Set(RobotMap::kIDLeft1Wheel);

  shifter.Set(static_cast<DoubleSolenoid::Value>(ShifterValue::kShifterLow));
}

void Chassis::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  defaultCommand = new TankDrive(true);
  SetDefaultCommand(defaultCommand);
}

TankDrive* Chassis::GetTankDriveCommand(){
  return defaultCommand;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::SetTankDrive(double left, double right) {
  right1Wheel.Set(right);
  left1Wheel.Set(left);
}
void Chassis::SetShifter(ShifterValue value){
  shifter.Set(static_cast<DoubleSolenoid::Value>(value));
}
bool Chassis::IsForwardTurretAlligned() const{
  return right2Wheel.IsFwdLimitSwitchClosed();
}

bool Chassis::IsRightTurretAlligned() const{
  return right2Wheel.IsRevLimitSwitchClosed();
}

double Chassis::GetLeftEncRPM() const {
  return left1Wheel.GetSpeed();
}

double Chassis::GetRightEncRPM() const {
  return right1Wheel.GetSpeed();
}

bool Chassis::IsShifterHigh() const {
 return shifter.Get() == static_cast<DoubleSolenoid::Value>(kShifterHigh);
}

bool Chassis::IsAutoShifterOn() const {
  return defaultCommand->IsAutoShifterEnabled();
}
