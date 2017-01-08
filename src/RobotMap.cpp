#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "CANTalon.h"

std::shared_ptr<CANTalon> RobotMap::chassisRight1Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight2Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisRight3Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft1Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft2Wheel;
std::shared_ptr<CANTalon> RobotMap::chassisLeft3Wheel;

void RobotMap::init() {
  LiveWindow *lw = LiveWindow::GetInstance();

  chassisRight1Wheel.reset(new CANTalon(kIDRightWheel1));
  lw->AddActuator("Chassis", "Right1Wheel", chassisRight1Wheel);

  chassisRight2Wheel.reset(new CANTalon(kIDRightWheel2));
  lw->AddActuator("Chassis", "Right2Wheel", chassisRight2Wheel);

  chassisRight3Wheel.reset(new CANTalon(kIDRightWheel3));
  lw->AddActuator("Chassis", "Right3Wheel", chassisRight3Wheel);

  chassisLeft1Wheel.reset(new CANTalon(kIDLeftWheel1));
  lw->AddActuator("Chassis", "Left1Wheel", chassisLeft1Wheel);

  chassisLeft2Wheel.reset(new CANTalon(kIDLeftWheel2));
  lw->AddActuator("Chassis", "Left2Wheel", chassisLeft2Wheel);

  chassisLeft3Wheel.reset(new CANTalon(kIDLeftWheel3));
  lw->AddActuator("Chassis", "Left3Wheel", chassisLeft3Wheel);
}
