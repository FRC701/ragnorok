#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "CANTalon.h"
#include "EStop.h"
#include "Commands/SetShooter.h"

class Shooter : public frc::Subsystem {
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Shooter> self;
  Shooter();

  robovikes::SetShooter* defaultCommand;
  EStop eStop;
  CANTalon top1FlyWheel;
  CANTalon top2FlyWheel;
  CANTalon bottomFlyWheel;
  double Tp;
  double Ti;
  double Td;
  double Tf;
  double Bp;
  double Bi;
  double Bd;
  double Bf;

public:

  static std::shared_ptr<Shooter> getInstance();

  void InitDefaultCommand();

  robovikes::SetShooter* GetSetShooterCommand();

  void SetCoast();

  void SetShooterRPM(double RPM);

  double GetOutputCurrent() const;

  double GetOutputVoltage() const;

  int GetEncoderVelocity() const;

  double GetSetPoint() const;

  int GetShooterError() const;

  double GetTopShooterRPM() const;
  double GetBottomShooterRPM() const;

};

#endif  // Shooter_H
