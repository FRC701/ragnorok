#include <Commands/SetConveyor.h>
#include "BallConveyor.h"
#include "../RobotMap.h"
#include "CANTalon.h"

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
  p(0.0), i(0.0), d(0.0), f(0.08)
{
  shooterFeeder.Enable();
  shooterFeeder.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  shooterFeeder.SetControlMode(frc::CANSpeedController::kSpeed);
  shooterFeeder.SetPID(p, i, d, f);
  shooterFeeder.SetInverted(true);
  shooterFeeder.SetSensorDirection(true);
  shooterFeeder.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
  shooterFeeder.ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);
}

void BallConveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ::SetConveyor(0.0));
}

void BallConveyor::SetConveyor(double conveyorSpeed)
{
  bool estophappened = false;

  if(eStop.ShouldStop(conveyorSpeed, GetBallConveyorRPM())){

    EStop::CancelCurrentCommand(GetCurrentCommand());

        estophappened = true;

      } else {
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




