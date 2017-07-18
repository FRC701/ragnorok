#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "CANTalon.h"

class RobotMap {
public:

//..........Talons..........

  //..........Chassis..........
  static const int kIDRight1Wheel = 1;
  static const int kIDRight2Wheel = 2;
  static const int kIDLeft1Wheel = 3;
  static const int kIDLeft2Wheel = 4;

  //..........BallConveyor..........
  static const int kIDShooterFeeder = 13;

  //..........GearPickup..........
  static const int kIDRoller = 10;

  //..........Intake..........
  static const int kIDFloorPickup = 9;

  //..........Lifter..........
  static const int kIDLeftClimber = 11;
  static const int kIDRightClimber = 12;

  //..........Shooter..........
  static const int kIDTop1FlyWheel = 5;
  static const int kIDTop2FlyWheel = 6;
  static const int kIDBottomFlyWheel = 7;

  //..........Turret..........
  static const int kIDTurretSpinner = 8;

//..........Pneumatics..........

  //..........Agitator..........
  static const int kIDAgitatorForward = 7;
  static const int kIDAgitatorReverse = 0;

  //..........GearPneumatics..........
  static const int kIDActuatorForward = 5;
  static const int kIDActuatorReverse = 2;
  static const int kIDSqueezerForward = 6;
  static const int kIDSqueezerReverse = 1;

  //..........ShiftingPneumatics..........
  static const int kIDShitftingForward = 3;
  static const int kIDShitftingReverse = 4;

//..........Lights..........
  static const int kIDRelay = 0;

//..........RPMConstants..........
  static const int kPeakPower = 937;

  static void init();
};
#endif
