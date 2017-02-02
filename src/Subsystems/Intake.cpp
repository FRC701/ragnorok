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
  floorPickup(RobotMap::kIDFloorPickup) {
  floorPickup.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
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
