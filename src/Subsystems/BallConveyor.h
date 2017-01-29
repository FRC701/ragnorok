#ifndef BallConveyor_H
#define BallConveyor_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>

class BallConveyor : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<BallConveyor> self;
  BallConveyor();

	CANTalon ConveyorMotor;

public:
	static std::shared_ptr<BallConveyor> getInstance();

	void InitDefaultCommand();

	void ConveyorControl(double conveyorSpeed);

	bool IsGearIn() const;

};

#endif  // BallConveyor_H
