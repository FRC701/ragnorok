#include "AutoLine.h"

namespace CenterGearTrajectories {
  extern const unsigned int kTrajectoryLength;
  extern const ChassisMotionProfileCommand::TrajectoryPoint leftTrajectories[];
  extern const ChassisMotionProfileCommand::TrajectoryPoint rightTrajectories[];
};

AutoLine::AutoLine()
: ChassisMotionProfileCommand(CenterGearTrajectories::rightTrajectories,
                              CenterGearTrajectories::leftTrajectories,
                              CenterGearTrajectories::kTrajectoryLength,
                              0.05)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}
