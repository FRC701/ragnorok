#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AutoCenterGear.h"
#include "Commands/AutoDrive.h"
#include "Commands/AutoLeftGear.h"
#include "Commands/AutoLine.h"
#include "Commands/AutoRightGear.h"
#include "Commands/Cancel.h"
#include "Commands/GearIntake.h"
#include "Commands/GearQuit.h"
#include "Commands/GearScore.h"
#include "Commands/SetGear.h"
#include "Commands/SetGearRoller.h"
#include "Commands/SetLifter.h"
#include "Commands/SetLightFlash.h"
#include "Commands/SetShifter.h"
#include "Commands/SetSqueeze.h"
#include "Commands/TankDrive.h"
#include "Commands/TimedDrive.h"
#include "Commands/ToggleAutoShifting.h"
#include "Commands/ToggleGear.h"
#include "Commands/ToggleLifter.h"
#include "Commands/ToggleShifter.h"
#include "Commands/ToggleSqueeze.h"
#include "Commands/ToggleTankDriveDirection.h"
#include "Subsystems/GearPickup.h"
#include "GenericHID.h"

std::shared_ptr<OI> OI::self;

std::shared_ptr<OI> OI::getInstance() {
  if (! self) {
    self = std::make_shared<OI>();
  }
  return self;
 }

OI::OI()
: driver(new Joystick(0))
, dA(driver.get(), kButtonA_ID)
, dB(driver.get(), kButtonB_ID)
, dX(driver.get(), kButtonX_ID)
, dY(driver.get(), kButtonY_ID)
, dLB(driver.get(), kButtonLB_ID)
, dRB(driver.get(), kButtonRB_ID)
, dL3(driver.get(), kButtonL3_ID)
, dR3(driver.get(), kButtonR3_ID)
, dStart(driver.get(), kButtonStart_ID)
, dBack(driver.get(), kButtonBack_ID)

, coDriver(new Joystick(1))
, coA(coDriver.get(), kButtonA_ID)
, coB(coDriver.get(), kButtonB_ID)
, coX(coDriver.get(), kButtonX_ID)
, coY(coDriver.get(), kButtonY_ID)
, coLB(coDriver.get(), kButtonLB_ID)
, coRB(coDriver.get(), kButtonRB_ID)
, coL3(coDriver.get(), kButtonL3_ID)
, coR3(coDriver.get(), kButtonR3_ID)
, coStart(coDriver.get(), kButtonStart_ID)
, coBack(coDriver.get(), kButtonBack_ID)

{
  // Process operator interface input here.
//-------------Driver--------

  dB.WhenPressed(new SetLifter(0.0));
  dY.WhenPressed(new SetLifter(1.0));
  dX.WhenPressed(new SetLifter(0.5));
  dA.WhenPressed(new GearIntake());
  dLB.WhenPressed(new ToggleTankDriveDirection());
  dL3.WhenPressed(new SetLightFlash(3));
  dRB.WhenPressed(new ToggleShifter());
  dStart.WhenPressed(new GearScore());
//  dBack.WhenPressed(new ToggleSqueeze());

//-------------CoDriver------

  coA.WhenPressed(new ToggleGear);

  coRB.WhenPressed(new GearIntake);
  coLB.WhenPressed(new GearScore);

  coY.WhenPressed(new SetLightFlash(3));


  //coLB.WhenPressed(new ());
  //coStart.WhenPressed(new ());
  //coBack.WhenPressed(new ());

  SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
  //SmartDashboard::PutData("Auto Line", new AutoLine());
  SmartDashboard::PutData("TEST ++", new AutoDrive(100,100));
  SmartDashboard::PutData("TEST +-", new AutoDrive(100,-100));
  SmartDashboard::PutData("TEST --", new AutoDrive(-100,-100));
  SmartDashboard::PutData("TEST -+", new AutoDrive(-100,100));
  SmartDashboard::PutData("TEST Right forw", new AutoDrive(0,10));
  SmartDashboard::PutData("TEST Right back", new AutoDrive(0,-10));
  SmartDashboard::PutData("Center Gear Start", new AutoDrive(-5.6371, 5.565));

  SmartDashboard::PutData("Auto Center Gear", new AutoCenterGear);
  SmartDashboard::PutData("Auto Left Gear", new AutoLeftGear);
  SmartDashboard::PutData("Auto Right Gear", new AutoRightGear);

  //..........Chassis..........

  SmartDashboard::PutData("Toggle AutoShift", new ToggleAutoShifting());	//TODO: these
  SmartDashboard::PutData("Toggle Shifter", new ToggleShifter());
  SmartDashboard::PutData("Set HighGear", new SetShifter(Chassis::kShifterHigh));
  SmartDashboard::PutData("Set LowGear", new SetShifter(Chassis::kShifterLow));
  SmartDashboard::PutData("Autodrive FWD 5", new AutoDrive(0, 0));
  SmartDashboard::PutData("Forward for 5 sec", new TimedDrive(5,1,1));

  //..........GearPickup..........

  SmartDashboard::PutData("Gear Up", new SetGear(GearPickup::kGearUp));
  SmartDashboard::PutData("Gear Down", new SetGear(GearPickup::kGearDown));
  SmartDashboard::PutData("Gear Roller On", new SetGearRoller(RobotMap::kPeakPower));
  SmartDashboard::PutData("Gear Roller Rev", new SetGearRoller(-RobotMap::kPeakPower));
  SmartDashboard::PutData("Squeeze Open", new SetSqueeze(GearPickup::kSqueezeOpen));
  SmartDashboard::PutData("Squeeze Close", new SetSqueeze(GearPickup::kSqueezeClosed));

  SmartDashboard::PutData("Gear Score", new GearScore());
  SmartDashboard::PutData("GearQuit", new GearQuit());
  SmartDashboard::PutData("Gear Intake", new GearIntake());

  //..........Lifter..........

  SmartDashboard::PutData("Lifter On", new SetLifter(1.0));
  SmartDashboard::PutData("Lifter Rev", new SetLifter(-1.0));
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

double OI::getDriverLeftTrigger() const {
  return driver->GetRawAxis(kLeftTrigger_ID);
}

double OI::getDriverRightTrigger() const {
  return driver->GetRawAxis(kRightTrigger_ID);
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

double OI::getCoDriverLeftTrigger() const {
  return coDriver->GetRawAxis(kLeftTrigger_ID);
}

double OI::getCoDriverRightTrigger() const {
  return coDriver->GetRawAxis(kRightTrigger_ID);
}

void OI::SetRumble(double amount) {
  driver->SetRumble(GenericHID::kLeftRumble, amount);
  coDriver->SetRumble(GenericHID::kLeftRumble, amount);
}
