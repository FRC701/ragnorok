#include "GearPickupInMotion.h"

namespace GearPickupTrajectories
{
	extern const unsigned int kTrajectoryLength;
	extern const TrajectoryPoint trajectory[];
}

static const int kMillis_50 = 50;

GearPickupInMotion::GearPickupInMotion()
: GearPickupMotionProfileCommand(GearPickupTrajectories::trajectory, GearPickupTrajectories::kTrajectoryLength, kMillis_50)
{
}

