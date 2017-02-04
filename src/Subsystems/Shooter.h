#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "CANTalon.h"

#include "Commands/SetShooter.h"

class Shooter : public frc::Subsystem {
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Shooter> self;

  robovikes::SetShooter* defaultCommand;

  CANTalon top1FlyWheel;
  CANTalon top2FlyWheel;
  CANTalon bottomFlyWheel;
  double p;
  double i;
  double d;

public:

  Shooter();

  static std::shared_ptr<Shooter> getInstance();

  void InitDefaultCommand();

  SetShooter* GetSetShooterCommand() const;


  void SetShooter(double RPM);

  double GetOutputCurrent() const;

  double GetOutputVoltage() const;

  int GetEncoderVelocity() const;

  double GetSetPoint() const;

  int GetShooterError() const;

  double GetTopShooterRPM() const;
  double GetBottomShooterRPM() const;
};

#endif  // Shooter_H
