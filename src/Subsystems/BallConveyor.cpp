#include <Commands/SetConveyor.h>
#include "BallConveyor.h"
#include "CANTalon.h"
#include "../RobotMap.h"

const char BallConveyor::kSubsystemName[] = "BallConveyor";

std::shared_ptr<BallConveyor> BallConveyor::self;

std::shared_ptr<BallConveyor> BallConveyor::getInstance() {
	if (! self) {
	  self = std::shared_ptr<BallConveyor>(new BallConveyor());
	}
	return self;
}

BallConveyor::BallConveyor() : Subsystem(kSubsystemName),
  eStop(0.5),
  shooterFeeder(RobotMap::kIDShooterFeeder),
  p(0.005), i(0.00001), d(0.0), f(0.09)
{
  shooterFeeder.SetControlMode(frc::CANSpeedController::kSpeed);
  shooterFeeder.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  shooterFeeder.SetPID(p, i, d, f);
  shooterFeeder.SetInverted(false);
  shooterFeeder.SetSensorDirection(true);
  shooterFeeder.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
  shooterFeeder.ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);
  shooterFeeder.Enable();
}

void BallConveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
  SetDefaultCommand(new ::SetConveyor(0.0));
}

void BallConveyor::SetConveyor(double conveyorSpeed)
{
  bool estophappened = false;

  if(eStop.ShouldStop(conveyorSpeed, GetBallConveyorRPM())){

    EStop::CancelCurrentCommand(GetCurrentCommand());
        estophappened = true;
    }
     else
     {
        shooterFeeder.Set(conveyorSpeed);
     }
      SmartDashboard::PutBoolean("ESTOP BallConveyor", estophappened);
}

bool BallConveyor::IsGearIn() const {
  return shooterFeeder.IsFwdLimitSwitchClosed();
}

double BallConveyor::GetBallConveyorRPM() const{
  return shooterFeeder.GetSpeed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
