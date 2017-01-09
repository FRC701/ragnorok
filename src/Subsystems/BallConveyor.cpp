#include "BallConveyor.h"
#include "../RobotMap.h"
#include "CANTalon.h"

const char BallConveyor::kSubsystemName[] = "BallConveyor";

std::shared_ptr<BallConveyor> BallConveyor::self;

std::shared_ptr<BallConveyor> BallConveyor::getInstance() {
	if (! self) {
	   self = std::make_shared<BallConveyor>();
	}
	return self;
}

BallConveyor::BallConveyor() : Subsystem(kSubsystemName),
	kID1(RobotMap::kID1),
	kID2(RobotMap::kID2)
		{

}

void BallConveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
