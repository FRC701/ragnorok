#include "BallConveyor.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/ConveyorControl.h"

const char BallConveyor::kSubsystemName[] = "BallConveyor";

std::shared_ptr<BallConveyor> BallConveyor::self;

std::shared_ptr<BallConveyor> BallConveyor::getInstance() {
	if (! self) {
	  self = std::shared_ptr<BallConveyor>(new BallConveyor());
	}
	return self;
}

BallConveyor::BallConveyor() : Subsystem(kSubsystemName),
  shooterFeeder(RobotMap::kIDShooterFeeder)
{
  shooterFeeder.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
}

void BallConveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ::ConveyorControl(0.0, 0.0));
}
void BallConveyor::ConveyorControl(double conveyorSpeed){

  shooterFeeder.Set(conveyorSpeed);
}

bool BallConveyor::IsGearIn() const {
  return shooterFeeder.IsFwdLimitSwitchClosed();
}

double BallConveyor::GetBallConveyorRPM() const{
  return shooterFeeder.GetSpeed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.




