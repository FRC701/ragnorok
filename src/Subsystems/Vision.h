#ifndef Vision_H
#define Vision_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class Vision : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<Vision> self;

public:
	static std::shared_ptr<Vision> getInstance();

	Vision();

	void InitDefaultCommand();
};

#endif  // Vision_H
