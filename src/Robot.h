#ifndef _ROBOT_H
#define _ROBOT_H

#include "LiveWindow/LiveWindow.h"
#include "OI.h"
#include "RobotMap.h"
#include "WPILib.h"

#include "Commands/Command.h"
#include "Commands/AutonomousCommand.h"

class Robot : public IterativeRobot {
public:
  Robot();

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	virtual void RobotPeriodic();

private:
  static std::unique_ptr<OI> oi;
  LiveWindow *lw = LiveWindow::GetInstance();
  frc::SendableChooser<frc::Command*> chooser;
  Command* autonomousCommand;

  Timer rumbler;
  bool rumbled;
  bool rumbling;

  void Rumbling();
};
#endif
