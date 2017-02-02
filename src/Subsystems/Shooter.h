#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "CANTalon.h"

class Shooter : public frc::Subsystem {
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Shooter> self;
  Shooter();
  
  CANTalon top1FlyWheel;
  CANTalon top2FlyWheel;
  CANTalon bottomFlyWheel;
  double p;
  double i;
  double d;
  double nudge;
  
public:
  static std::shared_ptr<Shooter> getInstance();

  void InitDefaultCommand();
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
