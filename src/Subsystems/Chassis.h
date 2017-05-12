#ifndef CHASSIS_H
#define CHASSIS_H

#include "CANTalon.h"
#include "Commands/Subsystem.h"
#include "Commands/TankDrive.h"
#include "DoubleSolenoid.h"

class Chassis: public frc::Subsystem {
private:
  // It's desirable that everything possible is private except
  // for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Chassis> self;
  Chassis();

  TankDrive* defaultCommand;

  CANTalon right1Wheel;
  CANTalon right2Wheel;
  CANTalon left1Wheel;
  CANTalon left2Wheel;
  DoubleSolenoid shifter;
  double p;
  double i;
  double d;

public:
  enum ShifterValue{kShifterHigh = DoubleSolenoid::kForward, kShifterLow = DoubleSolenoid::kReverse};
  enum AutoShifterValue{kAutoShiftOn = true, kAutoShiftOff = false};
//TODO Check to make sure shifter is high when forward

  static std::shared_ptr<Chassis> getInstance();

  void InitDefaultCommand();

  TankDrive* GetTankDriveCommand();

  void SetTankDrive(double left, double right);
  void SetShifter(ShifterValue value);
  void SetCoast();
  void SetBrake();
  void SetupPID();
  void ZeroPosition(); //This method is to be used in kPosition mode only
  void SetupDrive();

  bool Is0DegTurretAlligned() const;
  bool Is90DegTurretAlligned() const;
  bool IsShifterHigh() const;
  bool IsAutoShifterOn() const;

  double GetLeftEncRPM() const;
  double GetRightEncRPM() const;
  double GetDrivePosition() const;
  double GetDriveSetPoint() const;
  double GetRightDrivePosition() const;
  double GetLeftDrivePosition() const;
  double GetRightDriveSetPoint() const;
  double GetLeftDriveSetPoint() const;
  double GetPosition() const;

  void ConfigPeakOutput(double leftVolt, double rightVolt);

  /* Motion Profile Mode Support */
  void SetModeMotionProfile();
  void SetModePercentVBus();
  void SetSidePercentVBUS(char side);

  enum DriveSide { kDriveLeftSide, kDriveRightSide };
  void SetSidePercentVBus(DriveSide side);

  void ClearMotionProfileTrajectories();
  void SetMotionProfileSetValue(CANTalon::SetValueMotionProfile setValue);
  void PushMotionProfileTrajectory(const CANTalon::TrajectoryPoint& rightTrajectoryPoint,
                                   const CANTalon::TrajectoryPoint& leftTrajectoryPoint);
  void GetMotionProfileStatus(CANTalon::MotionProfileStatus* rightStatus,
                              CANTalon::MotionProfileStatus* leftStatus);
  void ProcessMotionProfileBuffer();
};

#endif
