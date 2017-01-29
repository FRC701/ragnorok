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


	CANTalon spinner;

public:
	static std::shared_ptr<Turret> getInstance();

	Turret();
	void InitDefaultCommand();

	void SetTurret(double speed);

	double GetTurret();

	bool IsLeftSwitchPressed() const;
//TODO Right Make sure these values correlate with how they go on the robot
	bool IsRightSwitchPressed() const;
};

#endif  // Turret_H
