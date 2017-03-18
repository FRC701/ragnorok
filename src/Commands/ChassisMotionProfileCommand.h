#ifndef ChasisMotionProfileCommand_H
#define ChassisMotionProfileCommand_H

#include <Commands/Command.h>
#include <Notifier.h>

class ChassisMotionProfileCommand : public Command {
public:
  struct TrajectoryPoint
  {
    double position;
    double velocity;
  };

  ChassisMotionProfileCommand(
      const TrajectoryPoint* chassisRight,
      const TrajectoryPoint* chassisLeft,
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
    virtual void run(const ChassisMotionProfileCommand*) = 0;
    virtual bool isFinished() const = 0;
    virtual MotionProfileState* getNextState() = 0;

    virtual ~MotionProfileState() { };
  };

  class MotionProfileLoad : public MotionProfileState
  {
  public:
    void run(const ChassisMotionProfileCommand* motionProfile);
    bool isFinished() const;
    ChassisMotionProfileCommand::MotionProfileState* getNextState();
    virtual ~MotionProfileLoad();
  };

private:
  friend class MotionProfileLoad;

  const TrajectoryPoint* chassisRight;
  const TrajectoryPoint* chassisLeft;
  unsigned int trajectoryPointCount;
  unsigned int pointDurationMillis;
  bool velocityOnly;

  Notifier notifier;
  MotionProfileState* state;

  void PeriodicTask();
};

#endif  // ChassisMotionProfileCommand_H
