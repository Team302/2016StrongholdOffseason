/*
 * Drive.cpp
 *
 *  Created on: Sep 12, 2016
 *      Author: Elite
 */

#include <Drive.h>
#include <RobotIO.h>
#include <DragonStick.h>
#include <DragonController.h>

Drive::Drive(DragonStick* driver, RobotIO* rIO)
{
	driveStick = driver;
	io = rIO;
	dragonControlLeftVel = new DragonController();
	dragonControlRightVel = new DragonController();
	isDone = true;

}

Drive::~Drive()
{
	// TODO Auto-generated destructor stub
}

 /*Teleop
  *allows for human operation of the drive system
  *
  */
 void Drive::Teleop(void)
 {
	 double lowGearSensitivity;
	 double triggerPressed;
	 double steer, throttle;
	 float leftSpeed, rightSpeed;
	 lowGearSensitivity = 0.45;
	 triggerPressed = driveStick->GetRawAxis(3);
	 if(triggerPressed > 0.80)
		 {
			 throttle = (double) invertAxis * (lowGearSensitivity - 0.1) * driveStick -> GetCubedAxis(AXIS_DRIVER_THROTTLE); //inverted throttle axis, cubed
			 steer = (double) invertAxis * lowGearSensitivity * (driveStick -> GetRawAxis(AXIS_DRIVER_STEER)); //apply sensitivity to steering2
		 }
	 else
	 {
		 //get axis value and assign as throttle or steering axis value
			 throttle = (double) invertAxis * driveStick -> GetCubedAxis(AXIS_DRIVER_THROTTLE); //inverted throttle axis, cubed
			 steer = (double) invertAxis * steerSensitivity * (driveStick -> GetRawAxis(AXIS_DRIVER_STEER)); //apply sensitivity to steering
	 }
	 SmartDashboard::PutNumber("Right Stickerooni",driveStick->GetRawAxis(AXIS_DRIVER_RIGHTSTICK));
	 SmartDashboard::PutNumber("Left Stickeridoo",driveStick->GetRawAxis(AXIS_DRIVER_THROTTLE));
	 //calculate left speed and right speed using arcade drive equations
	 //using subtract on the left speed assumes a value of -1 from the steering axis
	 //		indicates turning left
	 leftSpeed = throttle - steer;
	 rightSpeed = throttle + steer;

	 //send in range values to respective motors
	 io -> SetLeftSpeed(leftSpeed);
	 io -> SetRightSpeed(rightSpeed);

 }

 /*DriveDistance
  *drives a distance at the velocity given
  *updates the variable isDone
  */
void Drive::TeleopTank(void) //Made by Mike, The destroyer of minds and good code. You are welcome.
{
	float leftSpeed, rightSpeed;
	leftSpeed=driveStick->GetRawAxis(AXIS_DRIVER_THROTTLE);
	rightSpeed=driveStick->GetRawAxis(AXIS_DRIVER_RIGHTSTICK);
	io->SetLeftSpeed(-leftSpeed);
	io->SetRightSpeed(-rightSpeed);
}
 void Drive::DriveDistance(double distance, double velocity)
 {
	 //check distance traveled
	 //		if not there
	 //			let caller know not arrived yet isDone?
	 //			implement a p controller for velocity
	 //		if there
	 //			stop motors and let caller know of arrival isDone?
	 	 bool atTarget = false; //value to see if robot is at target yet
	 	 double targetVelocity = 0.0; //target velocity for motors
	 	 double motorRightOutput = 0.0; //output from p controller to right motors
	 	 double motorLeftOutput = 0.0; //output from p controller to left motors
	 	 double currentLeftVel = 0.0;//current velocity of left encoders
	 	 double currentRightVel = 0.0;//current velocity of right encoders
	 	 double currentLeftPos = 0.0; //current position of left encoders
	 	 double currentRightPos = 0.0; //current position of right encoders
	 	 double averagePos = 0.0; //average of encoder position values
	 	 double averageVel = 0.0; //average of encoder velocity values

	 	 currentLeftVel = io -> GetLeftVel();
	 	 currentRightVel = io -> GetRightVel();
	 	 currentLeftPos = io -> GetLeftDistance();
	 	 currentRightPos = io -> GetRightDistance();
	 	 averagePos = (currentLeftPos + currentRightPos) / 2; //average of encoder position values
	 	 averageVel = (currentLeftVel + currentRightVel) / 2; //average of encoder velocity values


	 	 if (averagePos <= distance) //Not yet at target, set velocity to target velocity
	 	 {
	 		 targetVelocity = velocity; //set target velocity to velocity requested
	 	 }
	 	 else //At or past target, set velocity targets to 0 to stop the robot
	 	 {
	 		 targetVelocity = 0.0;
	 		 atTarget = true; //robot is now at target
	 	 }

	 	 if (atTarget and (averageVel < 0.25)) //if robot is at target and is traveling less than .25 fps
	 	 {
	 		 isDone = true; //robot is done going to distance
	 	 }
	 	 else
	 	 {
	 		 isDone = false;
	 	 }

	 	 motorLeftOutput += dragonControlLeftVel -> PControl(currentLeftVel, targetVelocity, leftVelKp); //set motor output variables from p controllers
	 	 motorRightOutput += dragonControlRightVel -> PControl(currentRightVel, targetVelocity, rightVelKp); //+= is needed because it is velocity control

	 	 io -> SetLeftSpeed(motorLeftOutput); //set motor output to talon
	 	 io -> SetRightSpeed(motorRightOutput); //set motor output to talon

 }

 /*IsDoneDistance
  *returns the value of isDone to let the caller know that the Drive Distance method has finished
  *
  */
 bool Drive::IsDoneDistance()
 {
	 return isDone;
 }



