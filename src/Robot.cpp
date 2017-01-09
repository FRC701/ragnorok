#include "Robot.h"
#include "Subsystems/Chassis.h"

#include "Subsystems/BallConveyor.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Turret.h"
#include "Subsystems/Vision.h"
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
  OI::getInstance();
  BallConveyor::getInstance();
  Intake::getInstance();
  Shooter::getInstance();
  Turret::getInstance();
  Vision::getInstance();

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
  Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
  lw->Run();
}

START_ROBOT_CLASS(Robot);

