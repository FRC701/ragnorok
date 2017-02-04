#ifndef SetShooter_H
#define SetShooter_H

#include "Commands/Command.h"

namespace robovikes {

class SetShooter : public frc::Command {
public:
	SetShooter(double speed);
	void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

  double GetSpeed() const;
  void SetSpeed(double speed);
private:
	double mSpeed;
};

}

#endif  // SetShooter_H
