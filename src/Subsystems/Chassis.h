#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<CANTalon> right1Wheel;
	std::shared_ptr<CANTalon> right2Wheel;
	std::shared_ptr<CANTalon> right3Wheel;
	std::shared_ptr<CANTalon> left1Wheel;
	std::shared_ptr<CANTalon> left2Wheel;
	std::shared_ptr<CANTalon> left3Wheel;

public:
	Chassis();
	void InitDefaultCommand();

	void SetTankDrive(double left, double right);

};

#endif
