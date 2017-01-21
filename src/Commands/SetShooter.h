#ifndef SetShooter_H
#define SetShooter_H

#include "Commands/Command.h"

class SetShooter : public frc::Command {
public:
	SetShooter(double speed);
	void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

  void Nudge(double value);
private:
	double mSpeed;
};

#endif  // SetShooter_H
