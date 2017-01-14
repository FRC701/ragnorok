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

	CANTalon feederLeft;
	CANTalon feederRight;
	CANTalon moverMotor;

public:
	static std::shared_ptr<BallConveyor> getInstance();

	BallConveyor();

	void InitDefaultCommand();

	void ConveyorControl(double conveyorSpeed, double moverSpeed);

	double GetConveyorControl();
};

#endif  // BallConveyor_H
