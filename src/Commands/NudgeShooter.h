#ifndef NudgeShooter_H
#define NudgeShooter_H

#include "Commands/InstantCommand.h"

class NudgeShooter : public InstantCommand {
public:
  NudgeShooter(double nudge);
  void Initialize();

private:
  double mNudge;

};

#endif  // NudgeShooter_H
