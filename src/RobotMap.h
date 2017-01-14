#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "CANTalon.h"

class RobotMap {
public:

//..........Chassis..........
  static const int kIDRightWheel1 = 10;
  static const int kIDRightWheel2 = 11;
  static const int kIDRightWheel3 = 12;
  static const int kIDLeftWheel1 = 13;
  static const int kIDLeftWheel2 = 14;
  static const int kIDLeftWheel3 = 15;

//..........Testing/Implementation..........
  static const int kID1 = 1;
  static const int kID2 = 2;
  static const int kID3 = 3;
  static const int kID4 = 4;
  static const int kID5 = 5;
  static const int kID6 = 6;
  static const int kID7 = 7;
  static const int kID8 = 8;
  static const int kID9 = 9;
  static const int kID16 = 16;


	static void init();
};
#endif
