#ifndef Turret_H
#define Turret_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class Turret : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<Turret> self;

public:
	static std::shared_ptr<Turret> getInstance();

	Turret();
	void InitDefaultCommand();
};

#endif  // Turret_H
