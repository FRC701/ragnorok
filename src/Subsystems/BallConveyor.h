#ifndef BallConveyor_H
#define BallConveyor_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class BallConveyor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<BallConveyor> self;
public:
	static std::shared_ptr<BallConveyor> getInstance();

	BallConveyor();

	void InitDefaultCommand();
};

#endif  // BallConveyor_H
