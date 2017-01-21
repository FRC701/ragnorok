#ifndef Shooter_H
#define Shooter_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class Shooter : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Shooter> self;

  CANTalon rightMotor;
  CANTalon leftMotor;
  double p;
  double i;
  double d;
  double nudge;
public:
  static std::shared_ptr<Shooter> getInstance();


  Shooter();
  void InitDefaultCommand();

  void SetShooter(double speed);

  double GetShooter() const;

  int GetEncoderVelocity() const;

  void Nudge(double value);
};

#endif  // Shooter_H
