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
  AddSequential(new AutoDrive(-3.762, 3.673));
  AddSequential(new Delay(.25));
  AddSequential(new AutoDrive(-3.349, 0.856));
  AddSequential(new Delay(.25));//orig -4.2, 1.25
  AddSequential(new AutoDrive(-3.630, 3.722));
  AddSequential(new AutoGearScore);

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
