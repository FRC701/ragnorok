#include "Intake.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/SetIntake.h"
#include "EStop.h"

const char Intake::kSubsystemName[] = "Intake";

std::shared_ptr<Intake> Intake::self;

std::shared_ptr<Intake> Intake::getInstance() {
	if (! self) {
		self = std::shared_ptr<Intake>(new Intake);
	}
	return self;
}

Intake::Intake() : Subsystem(kSubsystemName),
  eStop(0.5),
  floorPickup(RobotMap::kIDFloorPickup),
  p(0.008), i(0.00009), d(0), f(0.08)
  {
  floorPickup.Enable();
  floorPickup.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  floorPickup.SetControlMode(frc::CANSpeedController::kSpeed);
  floorPickup.SetPID(p, i, d, f);
  floorPickup.SetInverted(true);
  floorPickup.SetSensorDirection(true);
  floorPickup.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
  floorPickup.ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);
  }
void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

  SetDefaultCommand(new ::SetIntake(0.0));
}

void Intake::SetIntake(double speed) {
	bool estophappened = false;

	if (eStop.ShouldStop(speed, GetIntakeRPM())) {
	    EStop::CancelCurrentCommand(GetCurrentCommand());

	    estophappened = true;

	  } else {
	    floorPickup.Set(speed);

	  }
	  SmartDashboard::PutBoolean("ESTOP Intake", estophappened);

}

double Intake::GetIntakeRPM() const{
  return floorPickup.GetSpeed();
  }

double Intake::GetIntakeCurrent() const {
  return floorPickup.GetOutputCurrent();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
