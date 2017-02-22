#include "Magazine.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "../Commands/AgitatorOff.h"

const char Magazine::kSubsystemName[] = "Magazine";

std::shared_ptr<Magazine> Magazine::self;

std::shared_ptr<Magazine> Magazine::getInstance() {
	if (! self) {
	  self = std::shared_ptr<Magazine>(new Magazine());
	}
	return self;
}

Magazine::Magazine() : Subsystem(kSubsystemName),
  agitator(RobotMap::kIDAgitatorForward, RobotMap::kIDAgitatorReverse),
  notifier(&Magazine::ToggleAgitator,this)
{
  SetAgitator(Magazine::kAgitatorIn);
}

void Magazine::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  //SetDefaultCommand(new );
	SetDefaultCommand(new AgitatorOff);
}

void Magazine::StartAgitator(double secondsToWait) {
  notifier.StartPeriodic(secondsToWait);
}

void Magazine::StopAgitator() {
  notifier.Stop();
}

void Magazine::SetAgitator(AgitatorValue value) {
  agitator.Set(static_cast<DoubleSolenoid::Value>(value));
}

void Magazine::ToggleAgitator() {
  AgitatorValue value
  	  = IsAgitatorOut() ? kAgitatorIn: kAgitatorOut;
  SetAgitator(value);
}

bool Magazine::IsAgitatorOut() const {
	return agitator.Get() == static_cast<DoubleSolenoid::Value>(kAgitatorOut);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.




