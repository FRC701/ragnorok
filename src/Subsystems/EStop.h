/*
 * EStop.h
 */

#ifndef SRC_SUBSYSTEMS_ESTOP_H_
#define SRC_SUBSYSTEMS_ESTOP_H_

#include "Timer.h"

class EStop
{
public:
  EStop (double defaultStallTime);
  virtual ~EStop ();

  enum {
    kDontStop = false,
    kStop = true
  };

  bool ShouldStop(double setSpeed, double currentSpeed);
private:
    Timer timer;
    double stallTime;
    double mDefaultStallTime;

    bool timerStarted;
    bool wasSetSpeedStopped;

    void StopTimer();

};

#endif /* SRC_SUBSYSTEMS_ESTOP_H_ */
