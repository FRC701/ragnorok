#include "AutoCenterGear.h"
#include "AutoDrive.h"
#include "AutoGearScore.h"

AutoCenterGear::AutoCenterGear() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.
  AddSequential(new AutoDrive(-5.7371, 5.765));
  AddSequential(new AutoGearScore);
// A command group will require all of the s

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
