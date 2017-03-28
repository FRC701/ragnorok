#ifndef AutoTurn_H
#define AutoTurn_H

#include "Commands/Command.h"

class AutoTurn : public Command {
public:
	AutoTurn(char side, double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	char mSide;
	double mDistance;
};

#endif  // AutoTurn_H
