#ifndef DefaultShooter_H
#define DefaultShooter_H

#include "Commands/Command.h"

class DefaultShooter : public frc::Command {
public:
	DefaultShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:

};

#endif  // DefaultShooter_H
