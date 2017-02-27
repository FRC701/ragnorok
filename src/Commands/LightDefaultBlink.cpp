#include "LightDefaultBlink.h"
#include "Lights.h"

LightDefaultBlink::LightDefaultBlink(double seconds) :
  mSeconds(seconds),
  notifier(&LightDefaultBlink::ToggleLights,this){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
  Requires(Lights::getInstance().get());
}

// Called just before this Command runs the first time
void LightDefaultBlink::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LightDefaultBlink::Execute() {
  SecondsToWait(mSeconds);
}

// Make this return true when this Command no longer needs to run execute()
bool LightDefaultBlink::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LightDefaultBlink::End() {
  notifier.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LightDefaultBlink::Interrupted() {
  notifier.Stop();
}

void LightDefaultBlink::SecondsToWait(double secondsToWait){
  notifier.StartPeriodic(secondsToWait);
}

void LightDefaultBlink::ToggleLights(){
  Lights::LightValue value
    = Lights::getInstance()->IsLightOn() ? Lights::kLightOff: Lights::kLightOn;
  Lights::getInstance()->SetGlow(value);
}
