#ifndef Lifter_H
#define Lifter_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class Lifter : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<Lifter> self;
	Lifter();

	CANTalon leftClimber;
	CANTalon rightClimber;

public:
	static std::shared_ptr<Lifter> getInstance();

	void InitDefaultCommand();

	void SetLifter(double speed);
	void SetBrake();

};

#endif  // Lifter_H
