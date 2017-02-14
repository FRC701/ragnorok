#ifndef Intake_H
#define Intake_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "EStop.h"

class Intake : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<Intake> self;
	Intake();
	EStop eStop;
	CANTalon floorPickup;
	double p;
	double i;
	double d;

public:
	static std::shared_ptr<Intake> getInstance();

	void InitDefaultCommand();
	void SetIntake(double speed);

	double GetIntakeRPM() const;
};

#endif  // Intake_H
