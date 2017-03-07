#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "Commands/Command.h"

class TankDrive: public frc::Command {
public:
	TankDrive(bool automaticShifting);

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

	void SetAutomaticShifting(bool automaticShifting);
	bool IsAutoShifterEnabled();

private:
  static const int kShiftUpVelocity =  1000;
  static const int kShiftDownVelocity = 0.75 * kShiftUpVelocity;

  void AutoShifting();

  bool mAutomaticShifting;
};

#endif
