#ifndef GearPickupMotionProfileCommand_H
#define GearPickupMotionProfileCommand_H

#include <Commands/Command.h>
#include <Notifier.h>

#include "MotionProfile.h"

class GearPickupMotionProfileCommand : public frc::Command {
public:
  GearPickupMotionProfileCommand(
      const TrajectoryPoint* trajectory,
      unsigned int trajectoryPointCount,
      unsigned int pointDurationMillis,
      bool velocityOnly = true);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

  class MotionProfileState
  {
  public:
    virtual void run(const GearPickupMotionProfileCommand*) = 0;
    virtual bool isFinished() const = 0;
    virtual MotionProfileState* getNextState() = 0;

    virtual ~MotionProfileState() { };
  };

  class MotionProfileLoad : public MotionProfileState
  {
  public:
    void run(const GearPickupMotionProfileCommand* motionProfile);
    bool isFinished() const;
    GearPickupMotionProfileCommand::MotionProfileState* getNextState();
    virtual ~MotionProfileLoad();
  };

private:
  friend class MotionProfileLoad;

  const TrajectoryPoint* trajectory;
  unsigned int trajectoryPointCount;
  unsigned int pointDurationMillis;
  bool velocityOnly;

  frc::Notifier notifier;
  MotionProfileState* state;

  void PeriodicTask();
};

#endif  // GearPickupMotionProfileCommand_H
