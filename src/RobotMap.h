#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "CANTalon.h"

class RobotMap {
public:

	static std::shared_ptr<CANTalon> chassisRight1Wheel;
	static std::shared_ptr<CANTalon> chassisRight2Wheel;
	static std::shared_ptr<CANTalon> chassisRight3Wheel;
	static std::shared_ptr<CANTalon> chassisLeft1Wheel;
	static std::shared_ptr<CANTalon> chassisLeft2Wheel;
	static std::shared_ptr<CANTalon> chassisLeft3Wheel;

	static void init();
};
#endif
