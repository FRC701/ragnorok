#include "Robot.h"
#include "OI.h"
#include <iostream>

#include "Subsystems/BallConveyor.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/GearPickup.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/Lights.h"
#include "Subsystems/Magazine.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Turret.h"
#include "Subsystems/Vision.h"

#include "Commands/AutoCenterGear.h"
#include "Commands/AutoLeftGear.h"
#include "Commands/AutoLine.h"
#include "Commands/AutoRightGear.h"
#include "Commands/AutoTimedCenterGear.h"
#include "Commands/SetShooter.h"
#include "Commands/AutoTimedCenterGear.h"

std::unique_ptr<OI> Robot::oi;

Robot::Robot()
: autonomousCommand(nullptr), rumbler(), rumbled(false),rumbling(false)
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
  BallConveyor::getInstance();
  Intake::getInstance();
  Magazine::getInstance();
  Shooter::getInstance();
  Turret::getInstance();
  Vision::getInstance();
  Lifter::getInstance();
  Lights::getInstance();
  OI::getInstance();

  // instantiate the command used for the autonomous period
  // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

  // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  chooser.AddDefault("Timed Drive Forward", new AutoTimedCenterGear);
  chooser.AddObject("Drive to Line", new AutoTimedCenterGear);  // todo: Make this AutoTimedDrive
  chooser.AddObject("Center Gear", new AutoCenterGear);
  chooser.AddObject("Left Gear", new AutoLeftGear);
  chooser.AddObject("Right Gear", new AutoRightGear);
  chooser.AddObject("Do Nothing", new AutonomousCommand);
  SmartDashboard::PutData("Choose Your Auto", &chooser);
}

void Robot::RobotPeriodic() {
  SmartDashboard::PutData("Choose Your Auto", &chooser);
}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
  SmartDashboard::PutData("Choose Your Auto", &chooser);
}

void Robot::DisabledPeriodic() {
  Scheduler::GetInstance()->Run();
  // Scheduler must start running before doing any operations
  // on subsystems or commands.
  Shooter::getInstance()->GetSetShooterCommand()->SetSpeed(0.0);
  Turret::getInstance()->GetSetPositionCommand()->SetPosition(0.0);
  SmartDashboard::PutData("Choose Your Auto", &chooser);
}

void Robot::AutonomousInit() {
  Chassis::getInstance()->SetShifter(Chassis::kShifterLow);

  autonomousCommand = new AutoRightGear;//chooser.GetSelected();
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
 // Chassis::getInstance()->SetCoast();Chassis::getInstance()->SetShifter(Chassis::kShifterHigh);
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
  SmartDashboard::PutNumber("Top Shooter EncoderRPM", Shooter::getInstance()->GetTopShooterRPM());
  SmartDashboard::PutNumber("Bot Shooter EncoderRPM", Shooter::getInstance()->GetBottomShooterRPM());
  SmartDashboard::PutNumber("Ball Intake EncoderRPM", Intake::getInstance()->GetIntakeRPM());
  SmartDashboard::PutNumber("Ball Conveyor EncoderRPM", BallConveyor::getInstance()->GetBallConveyorRPM());
  SmartDashboard::PutNumber("Lifter OutPut Voltage", Lifter::getInstance()->GetCurrent());


  SmartDashboard::PutNumber("Turret Current", Turret::getInstance()->GetTurretCurrent());
  SmartDashboard::PutNumber("Turret Voltage", Turret::getInstance()->GetTurretVoltage());
  SmartDashboard::PutNumber("Turret Position", Turret::getInstance()->GetTurretPosition());
  SmartDashboard::PutNumber("Turret SetPoint", Turret::getInstance()->GetSetPoint());

  SmartDashboard::PutNumber("Intake Current", Intake::getInstance()->GetIntakeCurrent());

  SmartDashboard::PutNumber("Top Shooter Setpoint", Shooter::getInstance()->GetSetPoint());

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

