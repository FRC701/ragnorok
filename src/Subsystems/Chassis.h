#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "CANTalon.h"

class Chassis: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

  static const char kSubsystemName[];
  static std::shared_ptr<Chassis> self;

  CANTalon right1Wheel;
	CANTalon right2Wheel;
	CANTalon left1Wheel;
	CANTalon left2Wheel;

public:
	static std::shared_ptr<Chassis> getInstance();

	Chassis();
	void InitDefaultCommand();

	void SetTankDrive(double left, double right);
};

#endif
