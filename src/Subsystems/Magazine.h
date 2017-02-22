#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include <DoubleSolenoid.h>
#include <Notifier.h>

class Magazine : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	static const char kSubsystemName[];
	static std::shared_ptr<Magazine> self;
  Magazine();

	DoubleSolenoid agitator;

	Notifier notifier;

public:
  static std::shared_ptr<Magazine> getInstance();

  enum AgitatorValue{
	  kAgitatorIn = DoubleSolenoid::kForward,
	  kAgitatorOut = DoubleSolenoid::kReverse};

  void InitDefaultCommand();
  void StartAgitator(double secondsToWait);
  void StopAgitator();
  void SetAgitator(AgitatorValue value);
  void ToggleAgitator();

  bool IsAgitatorOut() const;
};

#endif  // Magazine_H
