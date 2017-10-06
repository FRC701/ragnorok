#include "AutoLeftHopper.h"
#include "Delay.h"
#include "AutoDrive.h"
#include "NudgeShooter.h"
#include "SetConveyor.h"
#include "SetIntake.h"

AutoLeftHopper::AutoLeftHopper() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.
  AddSequential(new NudgeShooter(3275));
  AddParallel(new SetIntake(1000));
  AddParallel(new AutoDrive(6.584, -7.000));
  AddSequential(new Delay(2));
  AddSequential(new AutoDrive(0.632, -4.352));
  AddSequential(new Delay(1));
  AddSequential(new AutoDrive(2.161, -2.210));
  //AddSequential(new Delay(1));
  AddSequential(new SetConveyor(-1000));
  AddParallel(new SetIntake(1000));

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
