#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/TankDrive.h"

OI::OI() {
    // Process operator interface input here.

  driver.reset(new Joystick(0));
    
  dA.reset(new JoystickButton(driver.get(), 1));
  dA->WhileHeld(new AutonomousCommand());

    SmartDashboard::PutData("TankDrive", new TankDrive());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

}

std::shared_ptr<Joystick> OI::getDriver() {
   return driver;
}

double OI::getDriverLeftXAxis() const {
  return driver->GetRawAxis(kLeftXAxis_ID);
}

double OI::getDriverLeftYAxis() const {
  return driver->GetRawAxis(kLeftYAxis_ID);
}

double OI::getDriverRightXAxis() const {
  return driver->GetRawAxis(kRightXAxis_ID);
}

double OI::getDriverRightYAxis() const {
  return driver->GetRawAxis(kRightYAxis_ID);
}

double OI::getDriverTriggers() const {
  return driver->GetRawAxis(kTriggers_ID);
}


std::shared_ptr<Joystick> OI::getCoDriver() {
   return coDriver;
}

double OI::getCoDriverLeftXAxis() const {
  return coDriver->GetRawAxis(kLeftXAxis_ID);
}

double OI::getCoDriverLeftYAxis() const {
  return coDriver->GetRawAxis(kLeftYAxis_ID);
}

double OI::getCoDriverRightXAxis() const {
  return coDriver->GetRawAxis(kRightXAxis_ID);
}

double OI::getCoDriverRightYAxis() const {
  return coDriver->GetRawAxis(kRightYAxis_ID);
}

double OI::getCoDriverTriggers() const {
  return coDriver->GetRawAxis(kTriggers_ID);
}
