#include "AutoLeftGear.h"
#include "AutoDrive.h"
#include "Delay.h"
#include "AutoGearScore.h"
#include "SetShifter.h"
#include "SetGear.h"
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
      AddSequential(new SetShifter(Chassis::kShifterLow));
      AddSequential(new AutoDrive(-3.762, 3.673));
      AddSequential(new Delay(.5));
      AddSequential(new AutoDrive(-3.349, 0.856));
      AddSequential(new Delay(.5));//orig -4.2, 1.25
      AddSequential(new AutoDrive(-3.630, 3.722));
      AddSequential(new Delay(1));
      AddSequential(new AutoGearScore);
      AddSequential(new AutoDrive(3.0, -0.8));
      AddSequential(new SetGear(GearPickup::kGearUp));
      AddSequential(new AutoDrive(-5.062, 5.073));


	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
