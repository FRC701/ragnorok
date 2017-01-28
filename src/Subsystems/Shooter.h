#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "CANTalon.h"
#include "Timer.h"

class Shooter : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Shooter> self;

  Timer eStopTimer;
  bool eStopTimerStarted;
  CANTalon TopMotor1;
  CANTalon TopMotor2;
  CANTalon BottomMotor;
  double p;
  double i;
  double d;
  double nudge;

  bool checkEmergencyStop();
  void emergencyStop();
public:
  static std::shared_ptr<Shooter> getInstance();


  Shooter();
  void InitDefaultCommand();

  void SetShooter(double speed);

  double GetShooter() const;

  double GetOutputVoltage() const;

  double GetOutputCurrent() const;

  int GetEncoderVelocity() const;

  void Nudge(double value);

  double GetSetPoint() const;

  double GetSpeed() const;

  int GetShooterError() const;

  void Enable();

};

#endif  // Shooter_H
