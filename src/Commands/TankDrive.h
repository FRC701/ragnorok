// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class TankDrive: public frc::Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	TankDrive(bool automaticShifting);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

	void SetAutomaticShifting(bool automaticShifting);
	bool IsAutoShifterEnabled();

private:
  bool mAutomaticShifting;
  static const int kShiftUpVelocity =  1000;
  static const int kShiftDownVelocity = 0.75 * kShiftUpVelocity;

  void AutoShifting();
};

#endif
