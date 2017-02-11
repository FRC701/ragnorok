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
  roller(RobotMap::kIDRoller),
  actuator(RobotMap::kIDActuatorForward, RobotMap::kIDActuatorReverse),
  p(0.06), i(0.0), d(0.0)
{
  roller.Enable();
  roller.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  roller.SetControlMode(frc::CANSpeedController::kSpeed);
  roller.SetPID(p, i, d);
}

void GearPickup::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void GearPickup::SetGear(PickupValue value) {
  actuator.Set(static_cast<DoubleSolenoid::Value>(value));
}

bool GearPickup::IsGearUp() const {
  return actuator.Get() == static_cast<DoubleSolenoid::Value>(kGearUp);
}

bool GearPickup::IsGearAlligned() const{
  if(roller.IsFwdLimitSwitchClosed() && roller.IsRevLimitSwitchClosed()){
    return true;
  }
  else {
    return false;
  }
    }

double GearPickup::GetGearIntakeRPM() const{
  return roller.GetSpeed();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
