#ifndef Intake_H
#define Intake_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class Intake : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<Intake> self;

	CANTalon floorPickup;

public:
	static std::shared_ptr<Intake> getInstance();

	Intake();

	void InitDefaultCommand();
	void SetIntake(double speed);

	double GetIntakeRPM() const;
};

#endif  // Intake_H
