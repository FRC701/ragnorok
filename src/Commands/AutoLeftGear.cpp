#include "AutoLeftGear.h"
#include "AutoDrive.h"
#include "Delay.h"
#include "AutoGearScore.h"

AutoLeftGear::AutoLeftGear() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.
  AddSequential(new AutoDrive(-4.062, 3.973));
  AddSequential(new Delay(1));
  AddSequential(new AutoDrive(-3.499, 0.756));
  AddSequential(new Delay(1));//orig -4.2, 1.25
  AddSequential(new AutoDrive(-3.930, 4.022));
  AddSequential(new AutoGearScore);

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
