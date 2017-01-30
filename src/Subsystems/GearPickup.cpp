#include "GearPickup.h"
#include "../RobotMap.h"
#include <DoubleSolenoid.h>
#include "CANTalon.h"


const char GearPickup::kSubsystemName[] = "GearPickup";

std::shared_ptr<GearPickup> GearPickup::self;

std::shared_ptr<GearPickup> GearPickup::getInstance() {
  if(! self) {
    self = std::make_shared<GearPickup>();
  }
  return self;
}

GearPickup::GearPickup() : Subsystem(kSubsystemName),

    Roller(RobotMap::kIDRoller),
    Actuator(RobotMap::kIDActuatorForward, RobotMap::kIDActuatorReverse)

    {
  Roller.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
}

void GearPickup::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void GearPickup::SetGear(PickupValue value) {
  Actuator.Set(static_cast<DoubleSolenoid::Value>(value));
}

bool GearPickup::IsGearUp() const {
  return Actuator.Get() == static_cast<DoubleSolenoid::Value>(kGearUp);
}

bool GearPickup::IsGearAlligned() const{
  if(Roller.IsFwdLimitSwitchClosed() && Roller.IsRevLimitSwitchClosed()){
    return true;
  }
  else {
    return false;
  }
    }

double GearPickup::GetGearIntakeRPM() const{
  return Roller.GetSpeed();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
