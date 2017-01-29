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

  CANTalon FlyWheelTop1;
  CANTalon FlyWheelTop2;
  CANTalon FlyWheelBottom;
public:
  static std::shared_ptr<Shooter> getInstance();



  Shooter();
  void InitDefaultCommand();
  void SetShooter(double RPM);
//TODO Make sure these values allign with what is on the Robot
  bool IsLeftTurretAlligned() const;
  bool IsRightTurretAlligned() const;

  double GetTopShooterRPM() const;
  double GetBottomShooterRPM() const;
};

#endif  // Shooter_H
