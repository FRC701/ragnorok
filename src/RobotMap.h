#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "CANTalon.h"

class RobotMap {
public:

  static const int kIDRightWheel1 = 10;
  static const int kIDRightWheel2 = 11;
  static const int kIDRightWheel3 = 12;
  static const int kIDLeftWheel1 = 13;
  static const int kIDLeftWheel2 = 14;
  static const int kIDLeftWheel3 = 15;


  static std::shared_ptr<CANTalon> chassisRight1Wheel;
	static std::shared_ptr<CANTalon> chassisRight2Wheel;
	static std::shared_ptr<CANTalon> chassisRight3Wheel;
	static std::shared_ptr<CANTalon> chassisLeft1Wheel;
	static std::shared_ptr<CANTalon> chassisLeft2Wheel;
	static std::shared_ptr<CANTalon> chassisLeft3Wheel;

	static void init();
};
#endif
