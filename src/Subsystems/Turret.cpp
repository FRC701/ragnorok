#include "Turret.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "Commands/SetTurret.h"

const char Turret::kSubsystemName[] = "Turret";

std::shared_ptr<Turret> Turret::self;

std::shared_ptr<Turret> Turret::getInstance() {
	if (! self) {
		self = std::make_shared<Turret>();
	}
	return self;
}

Turret::Turret() : Subsystem(kSubsystemName),

    spinner(RobotMap::kIDTurretSpinner)
    {

}

void Turret::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ::SetTurret(0.0));
}

void Turret::SetTurret(double speed){

  spinner.Set(speed);

}
double Turret::GetTurret(){

  return spinner.Get();
}

bool Turret::IsLeftSwitchPressed() const{
  return spinner.IsFwdLimitSwitchClosed();
}

bool Turret::IsRightSwitchPressed() const{
  return spinner.IsRevLimitSwitchClosed();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
