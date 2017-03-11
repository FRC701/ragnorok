#include "GearPickup.h"
#include "../RobotMap.h"
#include <DoubleSolenoid.h>
#include "CANTalon.h"
#include "Commands/SetGearRoller.h"

const char GearPickup::kSubsystemName[] = "GearPickup";

std::shared_ptr<GearPickup> GearPickup::self;

std::shared_ptr<GearPickup> GearPickup::getInstance() {
  if(! self) {
  	self = std::shared_ptr<GearPickup>(new GearPickup);
  }
  return self;
}

GearPickup::GearPickup() : Subsystem(kSubsystemName),
  eStop(0.5),
  roller(RobotMap::kIDRoller),
  actuator(RobotMap::kIDActuatorForward, RobotMap::kIDActuatorReverse),
  squeezer(RobotMap::kIDSqueezerForward, RobotMap::kIDSqueezerReverse),
	p(0.08), i(0.001), d(0.0)
{
  roller.Enable();
  roller.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
  roller.SetControlMode(frc::CANSpeedController::kSpeed);
  roller.SetPID(p, i, d);
  roller.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
  roller.ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);

  SetGear(GearPickup::kGearUp);
  SetSqueeze(GearPickup::kSqueezeOpen);
}

void GearPickup::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  SetDefaultCommand(new SetGearRoller(0.0));
}

void GearPickup::SetGear(PickupValue value) {
  actuator.Set(static_cast<DoubleSolenoid::Value>(value));
}

void GearPickup::SetSqueeze(SqueezeValue value){
  squeezer.Set(static_cast<DoubleSolenoid::Value>(value));
}

bool GearPickup::IsGearUp() const {
  return actuator.Get() == static_cast<DoubleSolenoid::Value>(kGearUp);
}

bool GearPickup::IsGearIn() const{
  return roller.IsFwdLimitSwitchClosed();
    }

bool GearPickup::IsSqueezeOpen() const{
	return squeezer.Get() == static_cast<DoubleSolenoid::Value>(kSqueezeOpen);
}

void GearPickup::SetRollerSpeedRPM(double RPM)
{

  bool estophappened = false;

 if (eStop.ShouldStop(RPM, GetGearIntakeRPM())) {
    EStop::CancelCurrentCommand(GetCurrentCommand());

    estophappened = true;

  } else {
    roller.Set(RPM);

  }
  SmartDashboard::PutBoolean("ESTOP GearPickup", estophappened);
}

double GearPickup::GetGearIntakeRPM() const{
  return roller.GetSpeed();
}

bool GearPickup::IsFwdLimitSwitchClosed() const{
  return roller.IsFwdLimitSwitchClosed();
}

bool GearPickup::IsRevLimitSwitchClosed() const{
  return roller.IsRevLimitSwitchClosed();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
