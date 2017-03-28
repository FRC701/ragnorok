#ifndef AutoTurn_H
#define AutoTurn_H

#include "Commands/Command.h"

class AutoTurn : public Command {
public:
  enum TurnSide { kTurnLeftSide, kTurnRightSide };
	AutoTurn(TurnSide side, double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	TurnSide mSide;
	double mDistance;
};

#endif  // AutoTurn_H
