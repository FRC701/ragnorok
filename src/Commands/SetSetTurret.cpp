#include "SetSetTurret.h"
#include "../Subsystems/Turret.h"

SetSetTurret::SetSetTurret(double _position)
: position(_position)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called once when the command executes
void SetSetTurret::Initialize() {
  Turret::getInstance()->GetSetPositionCommand()->SetPosition(position);
}
