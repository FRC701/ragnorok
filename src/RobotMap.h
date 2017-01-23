#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "CANTalon.h"

class RobotMap {
public:

//..........Chassis..........
  static const int kIDRightWheel1 = 10;
  static const int kIDRightWheel2 = 11;
  static const int kIDRightWheel3 = 33;
  static const int kIDLeftWheel1 = 13;
  static const int kIDLeftWheel2 = 14;
  static const int kIDLeftWheel3 = 15;

//..........Testing/Implementation..........
  static const int kIDShooterRight = 1;
  static const int kIDShooterLeft = 7;
  static const int kIDIntakeRight = 2;
  static const int kIDIntakeLeft  = 4;
  static const int kIDConveyorFeederLeft = 8;
  static const int kIDConveyorFeederRight = 3;
  static const int kIDTurretSpinner = 6;
  static const int kIDConveyorMover = 5;
  static const int kID9 = 9;
  static const int kID16 = 16;


	static void init();
};
#endif
