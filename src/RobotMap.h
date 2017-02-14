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
  static const int kIDRoller = 3; //10

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

  //..........GearPneumatics..........
  static const int kIDActuatorForward = 1;
  static const int kIDActuatorReverse = 6;
  static const int kIDSqueezerForward = 2;
  static const int kIDSqueezerReverse = 5;

  //..........ShiftingPneumatics..........
  static const int kIDShitftingForward = 0;
  static const int kIDShitftingReverse = 7;
//TODO Check to make sure these values work on the Robot

  static void init();
};
#endif
