#ifndef TimedDrive_H
#define TimedDrive_H

#include "Commands/TimedCommand.h"

class TimedDrive : public TimedCommand {
public:
	TimedDrive(double timeout, double leftSpeed, double rightSpeed);
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
private:
	double mLeftSpeed, mRightSpeed;
};

#endif  // TimedDrive_H
