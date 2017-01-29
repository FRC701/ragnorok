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
  HopperRoller(RobotMap::kIDHopperIntake)
  {

  HopperRoller.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);

}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

  SetDefaultCommand(new ::SetIntake(0.0));
}

void Intake::SetIntake(double speed){

  HopperRoller.Set(speed);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
