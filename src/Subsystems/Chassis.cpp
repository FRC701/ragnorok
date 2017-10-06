#include "DoubleSolenoid.h"
#include "CANTalon.h"
#include "Chassis.h"
#include "LiveWindow/LiveWindow.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

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
  shifter(RobotMap::kIDShitftingForward, RobotMap::kIDShitftingReverse),
  p(7.0), i(0), d(0), f(0.1)
{

  frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

  lw->AddActuator(kSubsystemName , "Right1Wheel", right1Wheel);
  lw->AddActuator(kSubsystemName , "Right2Wheel", right2Wheel);
  lw->AddActuator(kSubsystemName , "Left1Wheel", left1Wheel);
  lw->AddActuator(kSubsystemName , "Left2Wheel", left2Wheel);

  SetUpTalon();
  SetupDrive();
  SetBrake();
  ZeroPosition();
  SetShifter(kShifterLow);
}

void Chassis::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  defaultCommand = new TankDrive(true);
  SetDefaultCommand(defaultCommand);
}

TankDrive* Chassis::GetTankDriveCommand(){
  return defaultCommand;
}

void Chassis::SetTankDrive(double left, double right) {
  left1Wheel.Set(left);
  right1Wheel.Set(right);
}

void Chassis::SetShifter(ShifterValue value){
  shifter.Set(static_cast<frc::DoubleSolenoid::Value>(value));
}

void Chassis::SetCoast() {
  right1Wheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
  right2Wheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
  left1Wheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
  left2Wheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
}

void Chassis::SetBrake() {
  right1Wheel.ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
  right2Wheel.ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
  left1Wheel.ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
  left2Wheel.ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
}

void Chassis::SetupPID() {
  right1Wheel.SetControlMode(CANTalon::kPosition);

  left1Wheel.SetInverted(false);
  left1Wheel.SetControlMode(CANTalon::kPosition);

  shifter.Set(static_cast<frc::DoubleSolenoid::Value>(ShifterValue::kShifterLow));
}

void Chassis::ConfigPeakOutput(double leftVolt, double rightVolt) {
  left1Wheel.ConfigPeakOutputVoltage(leftVolt,-leftVolt);
  right1Wheel.ConfigPeakOutputVoltage(rightVolt,-rightVolt);
}

void Chassis::ZeroPosition(){
  right1Wheel.SetPosition(0);
  left1Wheel.SetPosition(0);
}

void Chassis::SetupDrive() {
  right1Wheel.SetControlMode(CANTalon::kPercentVbus);

  left1Wheel.SetInverted(true);
  left1Wheel.SetControlMode(CANTalon::kPercentVbus);
}

bool Chassis::Is0DegTurretAlligned() const{
  return right2Wheel.IsFwdLimitSwitchClosed();
}

bool Chassis::Is90DegTurretAlligned() const{
  return right2Wheel.IsRevLimitSwitchClosed();
}

double Chassis::GetLeftEncRPM() const {
  return left1Wheel.GetSpeed();
}

double Chassis::GetRightEncRPM() const {
  return right1Wheel.GetSpeed();
}

double Chassis::GetDrivePosition() const {
  return right1Wheel.GetPosition();
}

double Chassis::GetRightDrivePosition() const {
  return right1Wheel.GetPosition();
}

double Chassis::GetLeftDrivePosition() const {
  return left1Wheel.GetPosition();
}

double Chassis::GetDriveSetPoint() const {
  return right1Wheel.GetSetpoint();
}

double Chassis::GetRightDriveSetPoint() const {
  return right1Wheel.GetSetpoint();
}

double Chassis::GetLeftDriveSetPoint() const {
  return left1Wheel.GetSetpoint();
}

bool Chassis::IsShifterHigh() const {
 return shifter.Get() == static_cast<frc::DoubleSolenoid::Value>(kShifterHigh);
}

bool Chassis::IsAutoShifterOn() const {
  return defaultCommand->IsAutoShifterEnabled();
}

void Chassis::SetModeMotionProfile() {
  right1Wheel.SetControlMode(CANTalon::kMotionProfile);
  left1Wheel.SetControlMode(CANTalon::kMotionProfile);
}

void Chassis::SetModePercentVBus() {
  right1Wheel.SetControlMode(CANTalon::kPercentVbus);
  left1Wheel.SetControlMode(CANTalon::kPercentVbus);
}

void Chassis::SetSidePercentVBus(DriveSide side) {
  switch (side)
  {
    case kDriveLeftSide:
      left1Wheel.SetControlMode(CANTalon::kPercentVbus);
      break;
    case kDriveRightSide:
      right1Wheel.SetControlMode(CANTalon::kPercentVbus);
      break;
  }
}

void Chassis::SetMotionProfileSetValue(CANTalon::SetValueMotionProfile setValue) {
  right1Wheel.Set(setValue);
  left1Wheel.Set(setValue);
}

void Chassis::ClearMotionProfileTrajectories() {
  right1Wheel.ClearMotionProfileTrajectories();
  left1Wheel.ClearMotionProfileTrajectories();
}

void Chassis::PushMotionProfileTrajectory(const CANTalon::TrajectoryPoint& rightTrajectoryPoint,
                                          const CANTalon::TrajectoryPoint& leftTrajectoryPoint) {
  right1Wheel.PushMotionProfileTrajectory(rightTrajectoryPoint);
  left1Wheel.PushMotionProfileTrajectory(rightTrajectoryPoint);
}

void Chassis::GetMotionProfileStatus(CANTalon::MotionProfileStatus* rightStatus,
                                     CANTalon::MotionProfileStatus* leftStatus) {
  right1Wheel.GetMotionProfileStatus(*rightStatus);
  left1Wheel.GetMotionProfileStatus(*leftStatus);
}

void Chassis::ProcessMotionProfileBuffer() {
  right1Wheel.ProcessMotionProfileBuffer();
  left1Wheel.ProcessMotionProfileBuffer();
}

void Chassis::SetUpTalon() {
  right1Wheel.SetInverted(false);
  right1Wheel.SetFeedbackDevice(CANTalon::QuadEncoder);
  right1Wheel.SetControlMode(CANTalon::kPercentVbus);
  right1Wheel.ConfigEncoderCodesPerRev(128);
  right1Wheel.ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);
  right1Wheel.SetSensorDirection(false);
  right1Wheel.SetPID(p, i ,d);

  left1Wheel.SetInverted(true);
  left1Wheel.SetFeedbackDevice(CANTalon::QuadEncoder);
  left1Wheel.SetControlMode(CANTalon::kPercentVbus);
  left1Wheel.ConfigEncoderCodesPerRev(128);
  left1Wheel.ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);
  left1Wheel.SetSensorDirection(false);
  left1Wheel.SetPID(p, i ,d);

  right2Wheel.SetControlMode(CANTalon::kFollower);
  right2Wheel.Set(RobotMap::kIDRight1Wheel);
  right2Wheel.ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);

  left2Wheel.SetControlMode(CANTalon::kFollower);
  left2Wheel.Set(RobotMap::kIDLeft1Wheel);
  left2Wheel.ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);
}
