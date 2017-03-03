#include "GearIntake.h"
#include "SetGear.h"
#include "SetSqueeze.h"
#include "SetGearRoller.h"
#include "../RobotMap.h"
#include "Delay.h"

GearIntake::GearIntake() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
  AddSequential(new SetGear(GearPickup::kGearDown));
  AddSequential(new SetSqueeze(GearPickup::kSqueezeOpen));
  AddSequential(new SetGearRoller(1200));
  AddSequential(new SetSqueeze(GearPickup::kSqueezeClosed));
  AddSequential(new SetGear(GearPickup::kGearUp));
	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
