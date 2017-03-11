#ifndef BallConveyor_H
#define BallConveyor_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "EStop.h"

class BallConveyor : public frc::Subsystem {
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<BallConveyor> self;
  BallConveyor();

  EStop eStop;
  CANTalon shooterFeeder;
  double p;
  double i;
  double d;

public:
  static std::shared_ptr<BallConveyor> getInstance();

  void InitDefaultCommand();
  void SetConveyor(double conveyorSpeed);

  bool IsGearIn() const;

  double GetBallConveyorRPM() const;
};

#endif  // BallConveyor_H
