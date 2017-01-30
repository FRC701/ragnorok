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

  CANTalon top1FlyWheel;
  CANTalon top2FlyWheel;
  CANTalon bottomFlyWheel;
public:
  static std::shared_ptr<Shooter> getInstance();



  Shooter();
  void InitDefaultCommand();
  void SetShooter(double RPM);

  double GetTopShooterRPM() const;
  double GetBottomShooterRPM() const;
};

#endif  // Shooter_H
