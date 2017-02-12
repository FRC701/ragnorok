#ifndef SetTurret_H
#define SetTurret_H

#include "Commands/Command.h"

namespace robovikes {

class SetTurret : public frc::Command {
public:
	SetTurret(double position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	double GetPosition() const;
	void SetPosition(double position);
private:
	double mPosition;
};

}
#endif  // SetTurret_H
