#ifndef Vision_H
#define Vision_H
#include <Commands/Subsystem.h>
#include "Devices/CANVision.h"

class Vision : public frc::Subsystem {
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Vision> self;
  Vision();

  CANVision vision;
public:
  static std::shared_ptr<Vision> getInstance();

  void InitDefaultCommand();

  int GetDistanceInches() const;
  int GetDeviationTicks() const;
};

#endif  // Vision_H
