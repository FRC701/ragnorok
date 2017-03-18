#include "AutoCenterGear.h"
#include "AutoDrive.h"
#include "GearScore.h"
#include "SetShifter.h"
#include "SetAutoShifter.h"
#include "Delay.h"
#include "SetGearRoller.h"
#include "../RobotMap.h"
#include "SetSqueeze.h"

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
  AddSequential(new SetAutoShifter(Chassis::kAutoShiftOff));
  AddSequential(new SetShifter(Chassis::kShifterLow));
  AddSequential(new AutoDrive(-5.771, 5.567));
  AddSequential(new SetSqueeze(GearPickup::kSqueezeOpen));
  AddSequential(new Delay(1));
  AddParallel(new GearScore());
  AddSequential(new SetGearRoller(-RobotMap::kPeakPower));
  AddParallel(new AutoDrive(2,-2));
  AddSequential(new SetGearRoller(-RobotMap::kPeakPower));

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
