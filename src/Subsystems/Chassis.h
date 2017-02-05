#ifndef CHASSIS_H
#define CHASSIS_H
#include "CANTalon.h"
#include "DoubleSolenoid.h"
#include "Commands/Subsystem.h"

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
	DoubleSolenoid shifter;

public:

	enum ShifterValue{kShifterHigh = DoubleSolenoid::kForward, kShifterLow = DoubleSolenoid::kReverse};
//TODO Check to make sure shifter is high when forward
	static std::shared_ptr<Chassis> getInstance();

	Chassis();

	void InitDefaultCommand();
	void SetTankDrive(double left, double right);
	void SetShifter(ShifterValue value);

	bool IsForwardTurretAlligned() const;
	bool IsRightTurretAlligned() const;
	bool IsShifterHigh() const;

	double GetLeftEncRPM() const;
	double GetRightEncRPM() const;
};

#endif
