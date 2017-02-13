#ifndef Turret_H
#define Turret_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>

#include "Commands/SetTurret.h"

class Turret : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<Turret> self;
	Turret();

	robovikes::SetTurret* defaultCommand;

	CANTalon turretSpinner;
  double p;
  double i;
  double d;

public:
	static std::shared_ptr<Turret> getInstance();

	void InitDefaultCommand();

	robovikes::SetTurret* GetSetPositionCommand();

	void SetTurret(double speed);

	double GetTurret();
	double GetSetPoint() const;
	double GetTurretPosition() const;
	//TODO Right Make sure these values correlate with how they go on the robot
	bool IsLeftSwitchPressed() const;
	bool IsRightSwitchPressed() const;
};

#endif  // Turret_H
