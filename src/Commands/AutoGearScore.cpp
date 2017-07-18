#include "AutoGearScore.h"
#include "Delay.h"
#include "SetGear.h"
#include "SetGearRoller.h"
#include "SetSqueeze.h"
#include "TimedDrive.h"

#include "../RobotMap.h"

AutoGearScore::AutoGearScore() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.
  AddSequential(new SetSqueeze(GearPickup::kSqueezeOpen));
  AddSequential(new SetGear(GearPickup::kGearDown));
  AddParallel(new Delay(1));
  AddSequential(new SetGearRoller(-RobotMap::kPeakPower));
  AddSequential(new SetGear(GearPickup::kGearDown));
  AddSequential(new TimedDrive(1,-.5,-.5));
// A command group will require all of the s
	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
