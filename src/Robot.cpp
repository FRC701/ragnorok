#include "Robot.h"
#include "OI.h"
#include <iostream>

#include "Subsystems/Chassis.h"
#include "Subsystems/GearPickup.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/Vision.h"
#include "Subsystems/Lights.h"

#include "Commands/AutoCenterGear.h"
#include "Commands/AutoLeftGear.h"
#include "Commands/AutoLine.h"
#include "Commands/AutoRightGear.h"

std::unique_ptr<OI> Robot::oi;

Robot::Robot()
: autonomousCommand(nullptr), rumbler(), rumbled(false), rumbling(false)
{
}

void Robot::RobotInit()
{
  RobotMap::init();
  // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

  // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
  // This MUST be here. If the OI creates Commands (which it very likely
  // will), constructing it during the construction of CommandBase (from
  // which commands extend), subsystems are not guaranteed to be
  // yet. Thus, their requires() statements may grab null pointers. Bad
  // news. Don't move it.
  Chassis::getInstance();
  Vision::getInstance();
  Lifter::getInstance();
  Lights::getInstance();
  OI::getInstance();

  //...........Some Test Camera Code.......



  // instantiate the command used for the autonomous period
  // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

  // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  chooser.AddDefault("Do Nothing", new AutonomousCommand);
  chooser.AddObject("Center Gear", new AutoCenterGear);
  chooser.AddObject("Left Gear", new AutoLeftGear);
  chooser.AddObject("Right Gear", new AutoRightGear);

  SmartDashboard::PutData("Choose Your Auto", &chooser);

  //...........Some Test Camera Code.......
 CameraServer::GetInstance()->StartAutomaticCapture().SetFPS(20);

}

void Robot::RobotPeriodic() {

}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
}

void Robot::DisabledPeriodic() {
  Scheduler::GetInstance()->Run();
  // Scheduler must start running before doing any operations
  // on subsystems or commands.
}

void Robot::AutonomousInit() {
  Chassis::getInstance()->SetShifter(Chassis::kShifterLow);

  autonomousCommand = chooser.GetSelected();
  autonomousCommand = new AutoRightGear;

  if (autonomousCommand != nullptr) {
      autonomousCommand->Start();
  }
}
void Robot::AutonomousPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  Chassis::getInstance()->ConfigPeakOutput(12,12);

  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // these lines or comment it out.
  if (autonomousCommand != nullptr)
    autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {

/*
  SmartDashboard::PutNumber("Shooter Velocity.", Shooter::getInstance()->GetEncoderVelocity());
  SmartDashboard::PutNumber("Shooter Voltage.", Shooter::getInstance()->GetOutputVoltage());
  SmartDashboard::PutNumber("Shooter Current.", Shooter::getInstance()->GetOutputCurrent());
  SmartDashboard::PutNumber("Turret Position", Turret::getInstance()->GetSetPoint());
  SmartDashboard::PutNumber("Turret Encoder Position Zero", Turret::getInstance()->GetTurretPosition());
*///this is commented out as to eliminate confusion when reading the dashboard
  SmartDashboard::PutNumber("Drive SetPosition", Chassis::getInstance()->GetDriveSetPoint());
  SmartDashboard::PutNumber("Drive CurrentPosition", Chassis::getInstance()->GetDrivePosition());
  SmartDashboard::PutBoolean("Drive Gear false=shifter low", Chassis::getInstance()->IsShifterHigh());
  SmartDashboard::PutNumber("Left Drive EncoderRPM", Chassis::getInstance()->GetLeftEncRPM());
  SmartDashboard::PutNumber("Right Drive EncoderRPM", Chassis::getInstance()->GetRightEncRPM());
  SmartDashboard::PutBoolean("Gear FwdBanner sensor true=triggered" , GearPickup::getInstance()->IsFwdLimitSwitchClosed());
  SmartDashboard::PutBoolean("Gear RevBanner sensor true=triggered", GearPickup::getInstance()->IsRevLimitSwitchClosed());
  SmartDashboard::PutBoolean("Gear Pneumatic false=low", GearPickup::getInstance()->IsGearUp());
  SmartDashboard::PutBoolean("Gear Squeezer false=open", GearPickup::getInstance()->IsSqueezeOpen());
  SmartDashboard::PutNumber("Gear Roller EncoderRPM", GearPickup::getInstance()->GetGearIntakeRPM());
  SmartDashboard::PutNumber("Lifter OutPut Voltage", Lifter::getInstance()->GetCurrent());

  SmartDashboard::PutBoolean("Is Gear In", GearPickup::getInstance()->IsGearIn());
  OI::getInstance()->SetRumble(1.0);
 ///*
  if(GearPickup::getInstance()->IsGearIn() && !rumbled) {
    //rumble for two
    if(!rumbling) {
      rumbler.Start();
      OI::getInstance()->SetRumble(1.0);
      rumbling = true;
    }
    if(rumbler.HasPeriodPassed(2)) {
      OI::getInstance()->SetRumble(0.0);
      rumbled = true;
    }
    else {
      OI::getInstance()->SetRumble(1.0);
    }
  }

  else {
    //dont rumble
    OI::getInstance()->SetRumble(0.0);
  }

  if(!GearPickup::getInstance()->IsGearIn()) {
    OI::getInstance()->SetRumble(0.0);
    rumbling = false;
    rumbled = false;
    rumbler.Stop();
    rumbler.Reset();
  }
//*/
  Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
  lw->Run();
}

void Robot::Rumbling(){
  OI::getInstance()->SetRumble(1.0);
}

START_ROBOT_CLASS(Robot);
