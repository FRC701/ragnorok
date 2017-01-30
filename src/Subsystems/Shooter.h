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

  CANTalon flyWheelTop1;
  CANTalon flyWheelTop2;
  CANTalon flyWheelBottom;
  double p;
  double i;
  double d;
  double nudge;
public:
  static std::shared_ptr<Shooter> getInstance();

  void InitDefaultCommand();

  void SetShooter(double speed);

  double GetShooter() const;

  double GetOutputVoltage() const;

  double GetOutputCurrent() const;

  int GetEncoderVelocity() const;

  double GetSetPoint() const;

  double GetSpeed() const;

  int GetShooterError() const;

  void Enable();
};

#endif  // Shooter_H
