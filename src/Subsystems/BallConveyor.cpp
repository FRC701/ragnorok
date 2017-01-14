#include "BallConveyor.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/ConveyorControl.h"

const char BallConveyor::kSubsystemName[] = "BallConveyor";

std::shared_ptr<BallConveyor> BallConveyor::self;

std::shared_ptr<BallConveyor> BallConveyor::getInstance() {
	if (! self) {
	   self = std::make_shared<BallConveyor>();
	}
	return self;
}

BallConveyor::BallConveyor() : Subsystem(kSubsystemName),
	feederLeft(RobotMap::kIDFeederLeft),
	feederRight(RobotMap::kIDFeederRight)
{
  feederRight.SetInverted(true);
}

void BallConveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ::ConveyorControl(0.0));
}
void BallConveyor::ConveyorControl(double speed){

// Put methods for controlling this subsystem
// here. Call these from Commands.
  feederLeft.Set(speed);
  feederRight.Set(speed);

}
  double BallConveyor::GetConveyorControl(){

  return feederLeft.Get();
}

