#include "Robot.h"
#include "OI.h"
#include "Subsystems/Chassis.h"
#include "Subsystems/BallConveyor.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Turret.h"
#include "Subsystems/Vision.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/GearPickup.h"

#include "Commands/SetShooter.h"

std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
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
  Shooter::getInstance();
  Turret::getInstance();
  Vision::getInstance();
  Lifter::getInstance();
  OI::getInstance();

  // instantiate the command used for the autonomous period
  // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  autonomousCommand.reset(new AutonomousCommand());

  // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
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
  Shooter::getInstance()->GetSetShooterCommand()->SetSpeed(0.0);
  Turret::getInstance()->GetSetPositionCommand()->SetPosition(0.0);
}

void Robot::AutonomousInit() {
  if (autonomousCommand.get() != nullptr)
    autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
  Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // these lines or comment it out.
  if (autonomousCommand.get() != nullptr)
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


  SmartDashboard::PutNumber("Turret Current", Turret::getInstance()->GetTurretCurrent());
  SmartDashboard::PutNumber("Turret Voltage", Turret::getInstance()->GetTurretVoltage());

  SmartDashboard::PutNumber("Intake Current", Intake::getInstance()->GetIntakeCurrent());

  Scheduler::GetInstance()->Run();

}

void Robot::TestPeriodic() {
  lw->Run();
}

START_ROBOT_CLASS(Robot);

