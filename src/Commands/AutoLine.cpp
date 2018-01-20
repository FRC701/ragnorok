#include "AutoLine.h"

namespace CenterGear {
	extern const unsigned int kTrajectoryLength;
	extern const ChassisMotionProfileCommand::TrajectoryPoint leftTrajectory[];
	extern const ChassisMotionProfileCommand::TrajectoryPoint rightTrajectory[];
};

static const int kMillis_50 = 50;

AutoLine::AutoLine()
: ChassisMotionProfileCommand(CenterGear::rightTrajectory, CenterGear::leftTrajectory, CenterGear::kTrajectoryLength, kMillis_50)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}
