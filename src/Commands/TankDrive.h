#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "Commands/Command.h"

class TankDrive: public frc::Command {
public:
  TankDrive(bool automaticShifting, bool tankDriveDirectionReversed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

	void SetAutomaticShifting(bool automaticShifting);
	bool IsAutoShifterEnabled();

	void SetTankDriveDirection(bool tankDriveDirectionReversed);
	bool IsTankDriveDirectionRevversed();

private:
  bool mAutomaticShifting;
  bool mTankDriveDirectionReversed;
  static const int kMaxLowGearRPM = 270;
  static const int kMaxHighGearRPM = 580;
  static const int kShiftUpVelocity =  0.75 * kMaxLowGearRPM;
  static const int kShiftDownVelocity = 0.75 * kShiftUpVelocity;

  void AutoShifting();
};

#endif
