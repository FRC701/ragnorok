#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

//..........driver..........

  std::shared_ptr<Joystick> driver;

  std::shared_ptr<JoystickButton> dA;
  std::shared_ptr<JoystickButton> dB;
  std::shared_ptr<JoystickButton> dX;
  std::shared_ptr<JoystickButton> dY;
  std::shared_ptr<JoystickButton> dLB;
  std::shared_ptr<JoystickButton> dRB;
  std::shared_ptr<JoystickButton> dL3;
  std::shared_ptr<JoystickButton> dR3;
  std::shared_ptr<JoystickButton> dStart;
  std::shared_ptr<JoystickButton> dBack;


//..........codriver..........

  std::shared_ptr<Joystick> coDriver;

  std::shared_ptr<JoystickButton> coA;
  std::shared_ptr<JoystickButton> coB;
  std::shared_ptr<JoystickButton> coX;
  std::shared_ptr<JoystickButton> coY;
  std::shared_ptr<JoystickButton> coLB;
  std::shared_ptr<JoystickButton> coRB;
  std::shared_ptr<JoystickButton> coL3;
  std::shared_ptr<JoystickButton> coR3;
  std::shared_ptr<JoystickButton> coStart;
  std::shared_ptr<JoystickButton> coBack;

public:
	OI();

//..........driver..........

  std::shared_ptr<Joystick> getDriver();

  double getDriverLeftXAxis() const;
  double getDriverLeftYAxis() const;

  double getDriverRightXAxis() const;
  double getDriverRightYAxis() const;

  double getDriverTriggers() const;


//..........driver..........

  std::shared_ptr<Joystick> getCoDriver();

  double getCoDriverLeftXAxis() const;
  double getCoDriverLeftYAxis() const;

  double getCoDriverRightXAxis() const;
  double getCoDriverRightYAxis() const;

  double getCoDriverTriggers() const;


//..........ids..........
  //TODO: check axis ids

  static const int kButtonA_ID = 1;
  static const int kButtonB_ID = 2;
  static const int kButtonX_ID = 3;
  static const int kButtonY_ID = 4;
  static const int kButtonLB_ID = 5;
  static const int kButtonRB_ID = 6;
  static const int kButtonBack_ID = 7;
  static const int kButtonStart_ID = 8;
  static const int kButtonL3_ID = 9;
  static const int kButtonR3_ID = 10;

  static const int kLeftXAxis_ID = 1;
  static const int kLeftYAxis_ID = 2;

  static const int kRightXAxis_ID = 4;
  static const int kRightYAxis_ID = 5;

  static const int kTriggers_ID = 3;
};

#endif
