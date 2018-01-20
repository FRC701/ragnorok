#include "Commands/GearPickupMotionProfileCommand.h"
#include "Subsystems/GearPickup.h"
#include "CANTalon.h"
#include <iostream>

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

using frc::Notifier;

namespace {

  const double kSecondsToMillis = 1000.0;
  const double kMillisToSeconds = ( 1.0 / kSecondsToMillis );

  void LoadPoints(
    const TrajectoryPoint* trajectory,
    unsigned int trajectoryPointCount,
    unsigned int pointDurationMillis,
    bool velocityOnly)

  {
    std::cout << "Load Points:" << trajectoryPointCount << std::endl;
    unsigned int lastPoint = trajectoryPointCount - 1;

    std::cout << trajectory << std::endl;
    std::cout << trajectory->velocity << std::endl;

    for (unsigned int point = 0; point < trajectoryPointCount; ++point) {
      if (point % 10 == 0) {
    	  std::cout << "LoadPoints:" << point << "," << trajectory[point].velocity << std::endl;
      }

      CANTalon::TrajectoryPoint trajectoryPoint;
      trajectoryPoint.position = trajectory[point].position;
      trajectoryPoint.velocity = trajectory[point].velocity;
      trajectoryPoint.timeDurMs = pointDurationMillis;
      trajectoryPoint.profileSlotSelect = 0;   // always slot 1
      trajectoryPoint.velocityOnly = velocityOnly;    // always both velocity and position
      trajectoryPoint.isLastPoint = (point == lastPoint);
      trajectoryPoint.zeroPos = (point == 0);

      GearPickup::getInstance()->PushMotionProfileTrajectory(trajectoryPoint);
      // std::cout << "LoadPoints: " << point << "," << trajectory[point].velocity << std::endl;
    }

    std::cout << "Load Points Complete"<< std::endl;
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

  class MotionProfileStart : public GearPickupMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const GearPickupMotionProfileCommand* motionProfile) {
      GearPickup::getInstance()->ClearMotionProfileTrajectories();
      GearPickup::getInstance()->SetMotionProfileSetValue(CANTalon::SetValueMotionProfileDisable);
      std::cout << "MotionProfileStart" << std::endl;
    }

    bool isFinished() const {
      return false;
    }

    GearPickupMotionProfileCommand::MotionProfileState* getNextState();

    virtual ~MotionProfileStart() { }
  };

  class MotionProfileLoadTalon : public GearPickupMotionProfileCommand::MotionProfileState
  {
  public:
    static const int kMinPointsInTalon = 5;

    void run(const GearPickupMotionProfileCommand* motionProfile) {
      GearPickup::getInstance()->SetMotionProfileSetValue(CANTalon::SetValueMotionProfileDisable);
    }

    bool isFinished() const {
      return false;
    }

    GearPickupMotionProfileCommand::MotionProfileState* getNextState();

    virtual ~MotionProfileLoadTalon() { }
  };

  class MotionProfileRun : public GearPickupMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const GearPickupMotionProfileCommand* motionProfile) {
      // std::cout << "MotionProfileRun::run" << std::endl;
      GearPickup::getInstance()->SetMotionProfileSetValue(CANTalon::SetValueMotionProfileEnable);
    }

    bool isFinished() const {
      return false;
    }

    GearPickupMotionProfileCommand::MotionProfileState* getNextState();

    virtual ~MotionProfileRun() { }
  };

  class MotionProfileFinished : public GearPickupMotionProfileCommand::MotionProfileState
  {
  public:
    void run(const GearPickupMotionProfileCommand* motionProfile) {
      std::cout << "MotionProfileFinished" << std::endl;
      GearPickup::getInstance()->SetMotionProfileSetValue(CANTalon::SetValueMotionProfileHold);
    }

    bool isFinished() const {
      return true;
    }

    GearPickupMotionProfileCommand::MotionProfileState* getNextState();

    virtual ~MotionProfileFinished() { }
  };

  MotionProfileStart motionProfileStart;
  GearPickupMotionProfileCommand::MotionProfileLoad motionProfileLoad;
  MotionProfileLoadTalon motionProfileLoadTalon;
  MotionProfileRun motionProfileRun;
  MotionProfileFinished motionProfileFinished;

  /**
   * The flyweight instances must be defined in order to implement the getNextState methods.
   */

  GearPickupMotionProfileCommand::MotionProfileState*
  MotionProfileStart::getNextState() {
    return &motionProfileLoad;
  }

  GearPickupMotionProfileCommand::MotionProfileState*
  MotionProfileLoadTalon::getNextState() {
    /**
     * The PeriodicTask will automatically load the Talons as the data points
     * are added. Presumably, by the time we check here, there are already
     * points in the Talon bottom buffer.
     */
    CANTalon::MotionProfileStatus status;
    GearPickup::getInstance()->GetMotionProfileStatus(&status);
//    std::cout << "MotionProfileStatus::getNextState" << " " << status.btmBufferCnt << std::endl;
	std::cout << "MotionProfileStatus::getNextState "
			<< "activePointValid:" << status.activePointValid << "\n"
			<< "btmBuffercnt:    " << status.btmBufferCnt << ","
			<< "hasUnderrun:     " << status.hasUnderrun << ","
			<< "isUnderrun:      " << status.isUnderrun << ","
			<< "topBufferCnt:    " << status.topBufferCnt
			<< std::endl;
    if (status.btmBufferCnt > kMinPointsInTalon) {
      return &motionProfileRun;
    }
    else {
      return this;
    }
  }

  GearPickupMotionProfileCommand::MotionProfileState*
  MotionProfileRun::getNextState() {
    CANTalon::MotionProfileStatus status;
    GearPickup::getInstance()->GetMotionProfileStatus(&status);
    // activePointValid must precede isLastPoint.
    if (status.btmBufferCnt % 10 == 0) {
		std::cout << "MotionProfileRun::getNextState" << " activePointValid:" << status.activePointValid << "\n"
				<< "btmBuffercnt: " << status.btmBufferCnt << ","
				<< "hasUnderrun:  " << status.hasUnderrun << ","
				<< "isUnderrun:   " << status.isUnderrun << ","
				<< "topBufferCnt: " << status.topBufferCnt
				<< std::endl;
    }
    if (status.activePointValid && status.activePoint.isLastPoint) {
      return &motionProfileFinished;
    } else {
      return this;
    }
  }

  GearPickupMotionProfileCommand::MotionProfileState*
  MotionProfileFinished::getNextState() {
    return this;
  }

} // end namespace

void GearPickupMotionProfileCommand::MotionProfileLoad::run(const GearPickupMotionProfileCommand* motionProfile) {
  std::cout << "MotionProfileLoad" << std::endl;
  LoadPoints(motionProfile->trajectory,
             motionProfile->trajectoryPointCount,
             motionProfile->pointDurationMillis,
             motionProfile->velocityOnly);
}

bool GearPickupMotionProfileCommand::MotionProfileLoad::isFinished() const {
  return false;
}

GearPickupMotionProfileCommand::MotionProfileState*
GearPickupMotionProfileCommand::MotionProfileLoad::getNextState() {
  return &motionProfileLoadTalon;
}

GearPickupMotionProfileCommand::MotionProfileLoad::~MotionProfileLoad() {
}


GearPickupMotionProfileCommand::GearPickupMotionProfileCommand(
  const TrajectoryPoint* _trajectory,
  unsigned int _trajectoryPointCount,
  unsigned int _pointDurationMillis,
  bool _velocityOnly)
: trajectory(_trajectory),
  trajectoryPointCount(_trajectoryPointCount),
  pointDurationMillis(_pointDurationMillis),
  velocityOnly(_velocityOnly),
  notifier(&GearPickupMotionProfileCommand::PeriodicTask, this),
  state(&motionProfileStart)
{
  Requires(GearPickup::getInstance().get());
  std::cout<<"GearPickupMotionProfileCommand Constructor"<<std::endl;
}

// Called just before this Command runs the first time
void GearPickupMotionProfileCommand::Initialize() {
  GearPickup::getInstance()->SetModeMotionProfile();
  notifier.StartPeriodic((pointDurationMillis * kMillisToSeconds) / 2.0);
  std::cout << "Start Periodic" << std::endl;
  state = &motionProfileStart;
}

// Called repeatedly when this Command is scheduled to run
void GearPickupMotionProfileCommand::Execute() {
  state->run(this);
  state = state->getNextState();
}

// Make this return true when this Command no longer needs to run execute()
bool GearPickupMotionProfileCommand::IsFinished() {
  return state->isFinished();
}

// Called once after isFinished returns true
void GearPickupMotionProfileCommand::End() {
  std::cout << "GearPickupMotionProfileCommand::End" << std::endl;
  notifier.Stop();
  GearPickup::getInstance()->SetModeSpeed();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearPickupMotionProfileCommand::Interrupted() {
  notifier.Stop();
  GearPickup::getInstance()->SetModeSpeed();
}

void GearPickupMotionProfileCommand::PeriodicTask() {
  GearPickup::getInstance()->ProcessMotionProfileBuffer();
}
