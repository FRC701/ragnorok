#include <Commands/ChassisMotionProfileCommand.h>
#include "Subsystems/Chassis.h"

/**
 * Notes about Talon Motion Profile
 *
 * The trajectory point buffer in the Talon Driver (RoboRio) is 2048 points.
 * The typical trajectory point is 10ms. 2048 represents 20.48 seconds of motion profile.
 *
 * Important -- The code in this implemenation does not support more than 2048 trajectory points.
 *
 * The trajectory point buffer in the Talon (bottom buffer) holds 128 points.
 *
 * The Talon Motion Profile Mode has three drive modes controlled by Set()
 * * Neutral (SetValueMotionProfileDisable)
 * * Drive (SetValueMotionProfileEnable)
 * * Hold (SetValueMotionProfileHold)
 *
 *
 */

namespace {

  const double kSecondsToMillis = 1000.0;
  const double kMillisToSeconds = ( 1.0 / kSecondsToMillis );

  void LoadPoints(
    const ChassisMotionProfileCommand::TrajectoryPoint* chassisRight,
    const ChassisMotionProfileCommand::TrajectoryPoint* chassisLeft,
    unsigned int trajectoryPointCount,
    unsigned int pointDurationMillis)
  {
    unsigned int lastPoint = trajectoryPointCount - 1;

    for (unsigned int point = 0; point < trajectoryPointCount; ++point) {
      CANTalon::TrajectoryPoint rightTrajectoryPoint;
      rightTrajectoryPoint.position = chassisRight[point].position;
      rightTrajectoryPoint.velocity = chassisRight[point].velocity;
      rightTrajectoryPoint.timeDurMs = pointDurationMillis;
      rightTrajectoryPoint.profileSlotSelect = 1;   // always slot 1
      rightTrajectoryPoint.velocityOnly = false;    // always both velocity and position
      rightTrajectoryPoint.isLastPoint = (point == lastPoint);
      rightTrajectoryPoint.zeroPos = (point == 0);

      CANTalon::TrajectoryPoint leftTrajectoryPoint = rightTrajectoryPoint;
      leftTrajectoryPoint.position = chassisLeft[point].position;
      leftTrajectoryPoint.velocity = chassisLeft[point].velocity;

      Chassis::getInstance()->PushMotionProfileTrajectory(rightTrajectoryPoint, leftTrajectoryPoint);
    }
  }

  /**
   * The MotionProfileState subclasses are implementations of the State Design Pattern
   * using the Flyweight implementation strategy.
   *
   * A flyweight class is one where the object instance holds no state so that there
   * is only ever one instance of the class.
   *
   * In this implementation each MotionProfileState class determines the next state in getNextState.
   */

  class MotionProfileStart : public ChassisMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const ChassisMotionProfileCommand* motionProfile) {
      Chassis::getInstance()->SetMotionProfileSetValue(CANTalon::SetValueMotionProfileDisable);
    }

    bool isFinished() const {
      return false;
    }

    ChassisMotionProfileCommand::MotionProfileState& getNextState();

    virtual ~MotionProfileStart() { }
  };

  class MotionProfileLoadTalon : public ChassisMotionProfileCommand::MotionProfileState
  {
  public:
    static const int kMinPointsInTalon = 5;

    void run(const ChassisMotionProfileCommand* motionProfile) {
      Chassis::getInstance()->SetMotionProfileSetValue(CANTalon::SetValueMotionProfileDisable);
    }

    bool isFinished() const {
      return false;
    }

    ChassisMotionProfileCommand::MotionProfileState& getNextState();

    virtual ~MotionProfileLoadTalon() { }
  };

  class MotionProfileRun : public ChassisMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const ChassisMotionProfileCommand* motionProfile) {
      Chassis::getInstance()->SetMotionProfileSetValue(CANTalon::SetValueMotionProfileEnable);
    }

    bool isFinished() const {
      return false;
    }

    ChassisMotionProfileCommand::MotionProfileState& getNextState();

    virtual ~MotionProfileRun() { }
  };

  class MotionProfileFinished : public ChassisMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const ChassisMotionProfileCommand* motionProfile) {
      Chassis::getInstance()->SetMotionProfileSetValue(CANTalon::SetValueMotionProfileHold);
    }

    bool isFinished() const {
      return true;
    }

    ChassisMotionProfileCommand::MotionProfileState& getNextState();

    virtual ~MotionProfileFinished() { }
  };

  MotionProfileStart motionProfileStart;
  ChassisMotionProfileCommand::MotionProfileLoad motionProfileLoad;
  MotionProfileLoadTalon motionProfileLoadTalon;
  MotionProfileRun motionProfileRun;
  MotionProfileFinished motionProfileFinished;

  /**
   * The flyweight instances must be defined in order to implement the getNextState methods.
   */

  ChassisMotionProfileCommand::MotionProfileState&
  MotionProfileStart::getNextState() {
    return motionProfileLoad;
  }

  ChassisMotionProfileCommand::MotionProfileState&
  MotionProfileLoadTalon::getNextState() {
    /**
     * The PeriodicTask will automatically load the Talons as the data points
     * are added. Presumably, by the time we check here, there are already
     * points in the Talon bottom buffer.
     */
    CANTalon::MotionProfileStatus rightStatus, leftStatus;
    Chassis::getInstance()->GetMotionProfileStatus(&rightStatus, &leftStatus);
    if (leftStatus.btmBufferCnt > kMinPointsInTalon
        && rightStatus.btmBufferCnt > kMinPointsInTalon) {
      return motionProfileRun;
    } else {
      return *this;
    }
  }

  ChassisMotionProfileCommand::MotionProfileState&
  MotionProfileRun::getNextState() {
    CANTalon::MotionProfileStatus rightStatus, leftStatus;
    Chassis::getInstance()->GetMotionProfileStatus(&rightStatus, &leftStatus);
    // activePointValid must precede isLastPoint.
    if (rightStatus.activePointValid && rightStatus.activePoint.isLastPoint
        && leftStatus.activePointValid && leftStatus.activePoint.isLastPoint) {
      return motionProfileFinished;
    } else {
      return *this;
    }
  }

  ChassisMotionProfileCommand::MotionProfileState&
  MotionProfileFinished::getNextState() {
    return *this;
  }

} // end namespace

void ChassisMotionProfileCommand::MotionProfileLoad::run(const ChassisMotionProfileCommand* motionProfile) {
  LoadPoints(motionProfile->chassisRight, motionProfile->chassisLeft,
             motionProfile->trajectoryPointCount, motionProfile->pointDurationMillis);
}

bool ChassisMotionProfileCommand::MotionProfileLoad::isFinished() const {
  return false;
}

ChassisMotionProfileCommand::MotionProfileState&
ChassisMotionProfileCommand::MotionProfileLoad::getNextState() {
  return motionProfileLoadTalon;
}

ChassisMotionProfileCommand::MotionProfileLoad::~MotionProfileLoad() {
}


ChassisMotionProfileCommand::ChassisMotionProfileCommand(
  const TrajectoryPoint* _chassisRight,
  const TrajectoryPoint* _chassisLeft,
  unsigned int _trajectoryPointCount,
  unsigned int _pointDurationMillis)
: chassisRight(_chassisRight),
  chassisLeft(_chassisLeft),
  trajectoryPointCount(_trajectoryPointCount),
  pointDurationMillis(_pointDurationMillis),
  notifier(&ChassisMotionProfileCommand::PeriodicTask, this),
  state(motionProfileStart)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Chassis::getInstance().get());
}

// Called just before this Command runs the first time
void ChassisMotionProfileCommand::Initialize() {
  Chassis::getInstance()->SetModeMotionProfile();
  notifier.StartPeriodic((pointDurationMillis * kMillisToSeconds) / 2.0);
  state = motionProfileStart;
}

// Called repeatedly when this Command is scheduled to run
void ChassisMotionProfileCommand::Execute() {
  state.run(this);
  state = state.getNextState();
}

// Make this return true when this Command no longer needs to run execute()
bool ChassisMotionProfileCommand::IsFinished() {
  return state.isFinished();
}

// Called once after isFinished returns true
void ChassisMotionProfileCommand::End() {
  notifier.Stop();
  Chassis::getInstance()->SetModePercentVBus();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisMotionProfileCommand::Interrupted() {
  notifier.Stop();
  Chassis::getInstance()->SetModePercentVBus();
}

void ChassisMotionProfileCommand::PeriodicTask() {
  Chassis::getInstance()->ProcessMotionProfileBuffer();
}
