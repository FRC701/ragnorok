#include "Intake.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/SetIntake.h"

const char Intake::kSubsystemName[] = "Intake";

std::shared_ptr<Intake> Intake::self;

std::shared_ptr<Intake> Intake::getInstance() {
	if (! self) {
		self = std::make_shared<Intake>();
	}
	return self;
}

Intake::Intake() : Subsystem(kSubsystemName),
  floorPickup(RobotMap::kIDFloorPickup),
  p(0.06), i(0.0), d(0)
  {
  floorPickup.Enable();
  floorPickup.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  floorPickup.SetControlMode(frc::CANSpeedController::kSpeed);
  floorPickup.SetControlMode(frc::CANSpeedController::kPercentVbus);//This is test code make sure to remove
  //floorPickup.SetPID(p, i, d);
  }
void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

  SetDefaultCommand(new ::SetIntake(0.0));
}

void Intake::SetIntake(double speed){
  floorPickup.Set(speed);
}

double Intake::GetIntakeRPM() const{
  return floorPickup.GetSpeed();
  }
// Put methods for controlling this subsystem
// here. Call these from Commands.
