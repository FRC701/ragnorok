#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Calibrate.h"
#include "Commands/FeedingShoot.h"
#include "Commands/NudgeShooter.h"
#include "Commands/NudgeTurret.h"
#include "Commands/SetConveyor.h"
#include "Commands/SetGear.h"
#include "Commands/SetGearRoller.h"
#include "Commands/SetIntake.h"
#include "Commands/SetLifter.h"
#include "Commands/SetShooter.h"
#include "Commands/SetSqueeze.h"
#include "Commands/SetTurret.h"
#include "Commands/TankDrive.h"
#include "Commands/ToggleAutoShifting.h"
#include "Commands/ToggleGear.h"
#include "Commands/ToggleShifter.h"
#include "Commands/ToggleSqueeze.h"
#include "Subsystems/GearPickup.h"

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
, coDriver(new Joystick(0))
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

  static const double kRPMNudge = 10.0;
  static const double kPositionNudge = 1.0;
//-------------Driver--------
  dA.WhenPressed(new NudgeShooter(kRPMNudge));
  dB.WhenPressed(new NudgeShooter(-kRPMNudge));
  dX.WhenPressed(new NudgeTurret(kPositionNudge));
  dY.WhenPressed(new NudgeTurret(-kPositionNudge));
//  dRB.WhenPressed(new ());
  dLB.WhenPressed(new ToggleShifter());
//  dStart.WhenPressed(new ());
//  dBack.WhenPressed(new ());
//-------------CoDriver------
/*  coA.WhenPressed(new ());
  coB.WhenPressed(new ());
  coX.WhenPressed(new ());
  coY.WhenPressed(new ());
  coRB.WhenPressed(new ());
  coLB.WhenPressed(new ());
  coStart.WhenPressed(new ());
  coBack.WhenPressed(new ()); */

  SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

  //..........Chassis..........

  SmartDashboard::PutData("Toggle AutoShift", new ToggleAutoShifting());	//TODO: these
  SmartDashboard::PutData("Toggle Shifter", new ToggleShifter());	//need set commands

  //..........Conveyor..........

  SmartDashboard::PutData("Convevor On", new SetConveyor(1000));
  SmartDashboard::PutData("Convevor Rev", new SetConveyor(-1000));

  //..........GearPickup..........

  SmartDashboard::PutData("Gear Up", new SetGear(GearPickup::kGearUp));
  SmartDashboard::PutData("Gear Down", new SetGear(GearPickup::kGearDown));
  SmartDashboard::PutData("Gear Roller On", new SetGearRoller(1000));
  SmartDashboard::PutData("Gear Roller Rev", new SetGearRoller(-1000));
  SmartDashboard::PutData("Squeeze Open", new SetSqueeze(GearPickup::kSqueezeOpen));
  SmartDashboard::PutData("Squeeze Down", new SetSqueeze(GearPickup::kSqueezeClosed));

  //..........Intake..........

  SmartDashboard::PutData("Intake On", new SetIntake(1000));
  SmartDashboard::PutData("Intake Rev", new SetIntake(-1000));

  //..........Lifter..........

  SmartDashboard::PutData("Lifter On", new SetLifter(1.0));
  SmartDashboard::PutData("Lifter Rev", new SetIntake(-1.0));

  //..........Shooter..........

  SmartDashboard::PutData("Shooter On", new robovikes::SetShooter(3000));
  SmartDashboard::PutData("Shooter Rev", new robovikes::SetShooter(-3000));

  //..........Turret..........

  SmartDashboard::PutData("Turret Calibrate", new Calibrate());
//  SmartDashboard::PutData("Turret On", new SetTurret()); TODO

  //..........Group..........
  SmartDashboard::PutData("Feeding Shoot", new FeedingShoot());
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
