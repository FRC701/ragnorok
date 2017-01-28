/**
 * This C++ FRC robot application is meant to demonstrate an example using the Motion Profile control mode
 * in Talon SRX.  The CANTalon class gives us the ability to buffer up trajectory points and execute them
 * as the roboRIO streams them into the Talon SRX.
 * 
 * There are many valid ways to use this feature and this example does not sufficiently demonstrate every possible
 * method.  Motion Profile streaming can be as complex as the developer needs it to be for advanced applications,
 * or it can be used in a simple fashion for fire-and-forget actions that require precise timing.
 * 
 * This application is an IterativeRobot project to demonstrate a minimal implementation not requiring the command 
 * framework, however these code excerpts could be moved into a command-based project.
 * 
 * The project also includes instrumentation.java which simply has debug printfs, and a MotionProfile.java which is generated
 * in @link https://docs.google.com/spreadsheets/d/1PgT10EeQiR92LNXEOEe3VGn737P7WDP4t0CQxQgC8k0/edit#gid=1813770630&vpid=A1
 * 
 * Logitech Gamepad mapping, use left y axis to drive Talon normally.  
 * Press and hold top-left-shoulder-button5 to put Talon into motion profile control mode.
 * This will start sending Motion Profile to Talon while Talon is neutral. 
 * This will signal Talon to fire MP.  When MP is done, Talon will "hold" the last setpoint position
 * and wait for another button6 press to fire again.
 * Release button5 to allow OpenVoltage control with left y axis.
 */
#include <Instrumentation.h>
#include "WPILib.h"
#include "MotionProfileExample.h"
#include "CANTalon.h"

class Robot: public frc::IterativeRobot
{
private:
  const int kLEFTWHEEL1 = 1;
  const int kLEFTWHEEL2 = 2;
  const int kLEFTWHEEL3 = 3;

  const int kRIGHTWHEEL1 = 4;
  const int kRIGHTWHEEL2 = 5;
  const int kRIGHTWHEEL3 = 6;

public:
	/** The Talon we want to motion profile. */
	CANTalon leftWheel1;
	CANTalon leftWheel2;
	CANTalon leftWheel3;

	CANTalon rightWheel1;
	CANTalon rightWheel2;
	CANTalon rightWheel3;

	/** some example logic on how one can manage an MP */
	MotionProfileExample leftMotionProfileControl;
	MotionProfileExample rightMotionProfileControl;
	
	/** joystick for testing */
	Joystick _joy;

	/** cache last buttons so we can detect press events.  In a command-based project you can leverage the on-press event
	 * but for this simple example, lets just do quick compares to prev-btn-states */
	bool _btnsLast[10] = {false,false,false,false,false,false,false,false,false,false};


	Robot() : leftWheel1(1), leftWheel2(2), leftWheel3(3),
	    rightWheel1(4), rightWheel2(5), rightWheel3(6),
	    leftMotionProfileControl(leftWheel1), rightMotionProfileControl(rightWheel1),
	    _joy(0)
	{
		leftWheel1.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
		leftWheel1.SetSensorDirection(true); /* keep sensor and motor in phase */
		leftWheel1.SetInverted(false);

		rightWheel1.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    rightWheel1.SetSensorDirection(false); /* keep sensor and motor in phase */
    rightWheel1.SetInverted(false);

    //Followers
    leftWheel2.SetControlMode(CANTalon::kFollower);
    leftWheel2.Set(kLEFTWHEEL1);
    leftWheel2.SetInverted(false);

    leftWheel3.SetControlMode(CANTalon::kFollower);
    leftWheel3.Set(kLEFTWHEEL1);
    leftWheel3.SetInverted(false);

    rightWheel2.SetControlMode(CANTalon::kFollower);
    rightWheel2.Set(kRIGHTWHEEL1);
    rightWheel2.SetInverted(false);

    rightWheel3.SetControlMode(CANTalon::kFollower);
    rightWheel3.Set(kRIGHTWHEEL1);
    rightWheel3.SetInverted(false);


	}
	/**  function is called periodically during operator control */
	void TeleopPeriodic()
	{
		/* get buttons */
		bool btns[10];
		for(unsigned int i=1;i<10;++i)
			btns[i] = _joy.GetRawButton(i);

		/* get the left joystick axis on Logitech Gampead */
		double leftYjoystick = _joy.GetY(); /* multiple by -1 so joystick forward is positive */
		double rightYjoystick = -1 * _joy.GetRawAxis(5);
		/* call this periodically, and catch the output.  Only apply it if user wants to run MP. */
		leftMotionProfileControl.control();
		rightMotionProfileControl.control();

		if (btns[1] == false) { /* Check button 5 (top left shoulder on the logitech gamead). */
			/*
			 * If it's not being pressed, just do a simple drive.  This
			 * could be a RobotDrive class or custom drivetrain logic.
			 * The point is we want the switch in and out of MP Control mode.*/

			/* button5 is off so straight drive */
			leftWheel1.SetControlMode(CANTalon::kVoltage);
			leftWheel1.Set(12.0 * leftYjoystick);

			rightWheel1.SetControlMode(CANTalon::kVoltage);
			rightWheel1.Set(12.0 * rightYjoystick);

			leftMotionProfileControl.reset();
			rightMotionProfileControl.reset();

		} else {
			/* Button5 is held down so switch to motion profile control mode => This is done in MotionProfileControl.
			 * When we transition from no-press to press,
			 * pass a "true" once to MotionProfileControl.
			 */
			leftWheel1.SetControlMode(CANTalon::kMotionProfile);
			rightWheel1.SetControlMode(CANTalon::kMotionProfile);

			CANTalon::SetValueMotionProfile setLeftOutput = leftMotionProfileControl.getSetValue();
			CANTalon::SetValueMotionProfile setRightOutput = rightMotionProfileControl.getSetValue();

			leftWheel1.Set(setLeftOutput);
			rightWheel1.Set(setRightOutput);

			/* if btn is pressed and was not pressed last time,
			 * In other words we just detected the on-press event.
			 * This will signal the robot to start a MP */
			if( (btns[2] == true) && (_btnsLast[2] == false) ) {
				/* user just tapped button 6 */

				//------------ We could start an MP if MP isn't already running ------------//
			  leftMotionProfileControl.start();
			  rightMotionProfileControl.start();
			}
		}

		/* save buttons states for on-press detection */
		for(int i=1;i<10;++i)
			_btnsLast[i] = btns[i];

	}

	void DisabledPeriodic()
	{
		/* it's generally a good idea to put motor controllers back
		 * into a known state when robot is disabled.  That way when you
		 * enable the robot doesn't just continue doing what it was doing before.
		 * BUT if that's what the application/testing requires than modify this accordingly */
		leftWheel1.SetControlMode(CANTalon::kPercentVbus);
		leftWheel1.Set( 0 );

		rightWheel1.SetControlMode(CANTalon::kPercentVbus);
		rightWheel1.Set( 0 );
		/* clear our buffer and put everything into a known state */
		leftMotionProfileControl.reset();
		rightMotionProfileControl.reset();
	}
};

START_ROBOT_CLASS(Robot)
