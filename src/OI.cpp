#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/AgitatorOn.h"
#include "Commands/AutoDrive.h"
#include "Commands/ShootAgitated.h"
#include "Commands/Calibrate.h"
#include "Commands/Cancel.h"
#include "Commands/FeedingShoot.h"
#include "Commands/GearIntake.h"
#include "Commands/GearQuit.h"
#include "Commands/GearScore.h"
#include "Commands/IntakeShoot.h"
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
#include "Commands/SetSetTurret.h"
#include "Commands/TankDrive.h"
#include "Commands/ToggleAutoShifting.h"
#include "Commands/ToggleGear.h"
#include "Commands/ToggleLifter.h"
#include "Commands/ToggleShifter.h"
#include "Commands/ToggleSqueeze.h"
#include "Commands/AutoLine.h"
#include "Subsystems/GearPickup.h"
#include "Subsystems/Turret.h"
#include "Commands/AutoCenterGear.h"
#include "Commands/AutoLeftGear.h"
#include "Commands/AutoRightGear.h"

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

,coTurretNeg90(coDriver.get(), kButtonCoTurretNeg90_ID)
,coTurret0(coDriver.get(), kButtonCoTurret0_ID)
,coTurret90(coDriver.get(), kButtonCoTurret90_ID )
,coTurretMinus(coDriver.get(), kButtonCoTurretMinus_ID)
,coTurretPlus(coDriver.get(), kButtonCoTurretPlus_ID)

,coShooterMinus(coDriver.get(), kButtonCoShooterMinus_ID)
,coShooterPlus(coDriver.get(), kButtonCoShooterPlus_ID)

,coShoot(coDriver.get(), kButtonCoShoot_ID)
,coBallIntake(coDriver.get(), kButtonCoBallIntake_ID)
,coGearScore(coDriver.get(), kButtonCoGearScore_ID)
,coGearPickup(coDriver.get(), kButtonCoGearPickup_ID)
,coGearToggle(coDriver.get(), kButtonCoGearToggle_ID)
,coBallOuttake(coDriver.get(), kButtonCoBallOuttake_ID)
,coFloorOuttake(coDriver.get(), kButtonCoFloorOuttake_ID)
,coCancel(coDriver.get(), kButtonCoCancel_ID)

{
  // Process operator interface input here.

  static const double kRPMNudge = 10.0;
  static const double kPositionNudge = 0.;
//-------------Driver--------

  dB.WhenPressed(new SetLifter(0.0));
  dY.WhenPressed(new SetLifter(1.0));
  dLB.WhenPressed(new ToggleShifter());
  dRB.WhenPressed(new ToggleAutoShifting());
  dStart.WhenPressed(new GearScore());
  dBack.WhenPressed(new Calibrate());

//-------------CoDriver------
  /*
  coA.WhenPressed(new SetIntake(RobotMap::kPeakPower));
  coB.WhenPressed(new GearQuit());
  coX.WhenPressed(new GearIntake());
  coY.WhenPressed(new GearScore());
  coRB.WhenPressed(new ShootAgitated());
  coStart.WhenPressed(new Cancel());
  coBack.WhenPressed(new Cancel());
  */

  coShoot.WhenPressed(new ShootAgitated);
  coBallIntake.WhenPressed(new SetIntake(RobotMap::kPeakPower));
  coGearScore.WhenPressed(new GearScore);
  coGearPickup.WhenPressed(new GearIntake);
  coGearToggle.WhenPressed(new ToggleGear);
  coFloorOuttake.WhenPressed(new SetIntake(-(   RobotMap::kPeakPower)));
  coCancel.WhenPressed((new Cancel));
  coTurretNeg90.WhenPressed(new SetSetTurret(Turret::getInstance()->kAtLeft));
  coTurret0.WhenPressed(new SetSetTurret(Turret::getInstance()->kAtRight/2));
  coTurret90.WhenPressed(new SetSetTurret(Turret::getInstance()->kAtRight));
  coTurretMinus.WhenPressed(new NudgeTurret(-Turret::kPNudge));
  coTurretPlus.WhenPressed(new NudgeTurret(Turret::kPNudge));
  coShooterPlus.WhenPressed(new NudgeShooter(100));
  coShooterMinus.WhenPressed(new NudgeShooter(-100));

  /*
//........Driver Buttons....
  dA.WhenPressed(new NudgeShooter(kRPMNudge));
  dB.WhenPressed(new NudgeShooter(-kRPMNudge));
  dX.WhenPressed(new NudgeTurret(Turret::getInstance()->kPNudge));
  dY.WhenPressed(new NudgeTurret(-Turret::getInstance()->kPNudge));
//  dRB.WhenPressed(new ());
  dLB.WhenPressed(new ToggleShifter());
//  dStart.WhenPressed(new ());
//  dBack.WhenPressed(new ());
//-------------CoDriver Buttons------
    coA.WhenPressed(new ());
  coB.WhenPressed(new ());
  coX.WhenPressed(new ());
  coY.WhenPressed(new ());
  coRB.WhenPressed(new ());
  coLB.WhenPressed(new ());
  coStart.WhenPressed(new ());
  coBack.WhenPressed(new ()); */

  SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
  SmartDashboard::PutData("Auto Line", new AutoLine());

  SmartDashboard::PutData("Auto Center Gear", new AutoCenterGear);
  SmartDashboard::PutData("Auto Left Gear", new AutoLeftGear);
  SmartDashboard::PutData("Auto Right Gear", new AutoRightGear);

  //..........Chassis..........

  SmartDashboard::PutData("Toggle AutoShift", new ToggleAutoShifting());	//TODO: these
  SmartDashboard::PutData("Toggle Shifter", new ToggleShifter());	//need set commands
  SmartDashboard::PutData("Autodrive FWD 5", new AutoDrive(-5.971, 5.767));

  //..........Conveyor..........

  SmartDashboard::PutData("Convevor On", new SetConveyor(RobotMap::kPeakPower));
  SmartDashboard::PutData("Convevor Rev", new SetConveyor(-RobotMap::kPeakPower));

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

  //..........Intake..........

  SmartDashboard::PutData("Intake On", new SetIntake(RobotMap::kPeakPower));
  SmartDashboard::PutData("Intake Rev", new SetIntake(-RobotMap::kPeakPower));

  //..........Lifter..........

  SmartDashboard::PutData("Lifter On", new SetLifter(1.0));
  SmartDashboard::PutData("Lifter Rev", new SetLifter(-1.0));

  //..........Magazine..........

  SmartDashboard::PutData("Agitator On", new AgitatorOn);

  //..........Shooter..........

  SmartDashboard::PutData("Shooter On", new robovikes::SetShooter(3000));
  SmartDashboard::PutData("Shooter Rev", new robovikes::SetShooter(-3000));

  SmartDashboard::PutData("Shooter Nudge -100", new NudgeShooter(-100));
  SmartDashboard::PutData("Shooter Nudge 100", new NudgeShooter(100));

  //..........Turret..........

  SmartDashboard::PutData("Turret Calibrate", new Calibrate());
  SmartDashboard::PutData("Turret Set half", new  robovikes::SetTurret(Turret::getInstance()->kAtBothMags));
  SmartDashboard::PutData("Turret Set 0", new  robovikes::SetTurret(0));
//  SmartDashboard::PutData("Turret On", new SetTurret()); TODO

  //..........Group..........
  SmartDashboard::PutData("Feeding Shoot", new FeedingShoot());
  SmartDashboard::PutData("Intake Shoot", new IntakeShoot());
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
