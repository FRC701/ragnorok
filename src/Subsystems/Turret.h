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
	double GetTurret() const;

	double GetSetPoint() const;
	double GetTurretPosition() const;
	void SetTurretPosition(double position);

  bool IsRightStopperHit() const;
  bool IsLeftStopperHit() const;

	void Calibrate();
	void FinishCalibrate(double newPosition);

	//TODO Make sure these values correlate with how they go on the robot
	const double kAtLeft = 0;
	const double kAtRight = 1000;
  const double kAtBothMags = 500;
  const double kAt0Mag = 750;
};

#endif  // Turret_H
