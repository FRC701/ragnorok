#include "AutoLine.h"

namespace CenterGear {
  const unsigned int kTrajectoryLength = 93;
  const ChassisMotionProfileCommand::TrajectoryPoint* leftTrajectories;
  const ChassisMotionProfileCommand::TrajectoryPoint* rightTrajectories;
}

AutoLine::AutoLine()
: ChassisMotionProfileCommand(CenterGear::rightTrajectories, CenterGear::leftTrajectories, CenterGear::kTrajectoryLength, 0.05)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}
