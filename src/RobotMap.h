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
  static const int kIDLifterLeft = 11;
  static const int kIDLifterRight = 12;

  //..........Shooter..........
  static const int kIDFlyWheelTop1 = 5;
  static const int kIDFlyWheelTop2 = 6;
  static const int kIDFlyWheelBottom = 7;

  //..........Turret..........
  static const int kIDTurretSpinner = 8;

//..........Pneumatics..........

  //..........GearPneumatics..........
  static const int kIDpickupForward = 1;
  static const int kIDpickupReverse = 6;

  //..........ShiftingPneumatics..........
  static const int kIDShitftingHigh = 0;
  static const int kIDShitftingLow = 7;






	static void init();
};
#endif
