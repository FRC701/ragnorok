#ifndef SetShooter_H
#define SetShooter_H

#include "Commands/Command.h"

class SetShooter : public frc::InstantCommand {
public:
	SetShooter(double speed);
	void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
private:
	double mSpeed;
};

#endif  // SetShooter_H
