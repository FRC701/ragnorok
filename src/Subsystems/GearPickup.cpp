#include "GearPickup.h"
#include "../RobotMap.h"
#include <DoubleSolenoid.h>


const char GearPickup::kSubsystemName[] = "GearPickup";

std::shared_ptr<GearPickup> GearPickup::self;

std::shared_ptr<GearPickup> GearPickup::getInstance() {
  if(! self) {
    self = std::make_shared<GearPickup>();
  }
  return self;
}

GearPickup::GearPickup() : Subsystem(kSubsystemName),

    GearRoller(RobotMap::kIDGearIntake),
    Pickup(RobotMap::kIDpickupForward, RobotMap::kIDpickupReverse)

    {

}

void GearPickup::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void GearPickup::SetGear(PickupValue value) {
  Pickup.Set(static_cast<DoubleSolenoid::Value>(value));
}

bool GearPickup::IsGearUp() const {
  return Pickup.Get() == static_cast<DoubleSolenoid::Value>(kGearUp);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
