#ifndef Turret_H
#define Turret_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class Turret : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<Turret> self;


	CANTalon turretSpinner;
  double p;
  double i;
  double d;

public:
	static std::shared_ptr<Turret> getInstance();

	Turret();
	void InitDefaultCommand();
	void SetTurret(double speed);

	double GetTurret();
	//TODO Right Make sure these values correlate with how they go on the robot
	bool IsLeftSwitchPressed() const;
	bool IsRightSwitchPressed() const;
};

#endif  // Turret_H
