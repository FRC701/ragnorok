#ifndef AutoDrive_H
#define AutoDrive_H

#include "Commands/Command.h"

class AutoDrive : public Command {
public:
	AutoDrive(double Leftdistance, double Rightdistance);
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double mLeftDistance;
	double mRightDistance;
};

#endif  // AutoDrive_H
