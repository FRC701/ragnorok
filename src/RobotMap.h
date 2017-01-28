#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "CANTalon.h"

class RobotMap {
public:

//..........Talons..........

  //..........Chassis..........
  static const int kIDRightWheel1 = 1;
  static const int kIDRightWheel2 = 2;
  static const int kIDLeftWheel1 = 3;
  static const int kIDLeftWheel2 = 4;

  //..........Conveyor..........
  static const int kIDConveyor = 13;

  //..........GearIntake..........
  static const int kIDGearIntake = 10;

  //..........HopperIntake..........
  static const int kIDHopperIntake = 9;

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

  //..........ShiftingPneumatics..........
  static const int kIDShitftingForward = 0;
  static const int kIDShitftingReverse = 7;

  //..........GearPneumatics..........
  static const int kIDpickupForward = 1;
  static const int kIDpickupReverse = 6;

  static void init();
};
#endif
