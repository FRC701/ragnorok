#include "AutoDrive.h"
#include "AutoGearScore.h"
#include "AutoRightGear.h"
#include "AutoTurn.h"
#include "Delay.h"
#include "GearScore.h"
#include "SetAutoShifter.h"
#include "SetGear.h"
#include "SetGearRoller.h"
#include "SetShifter.h"
#include "SetSqueeze.h"
#include "TimedDrive.h"
#include "../RobotMap.h"

AutoRightGear::AutoRightGear() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.
  AddSequential(new SetAutoShifter(Chassis::kAutoShiftOff));
  AddSequential(new SetShifter(Chassis::kShifterLow));
  AddSequential(new AutoDrive(-3.962, 3.873));
  AddSequential(new AutoDrive(-0.756, 3.499));//orig -1.25, 4.2
  AddSequential(new AutoDrive(-3.930, 4.022));

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
//
}
