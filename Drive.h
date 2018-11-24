/*
 * Drive.h
 *
 *  Created on: Sep 12, 2016
 *      Author: Elite
 */

#ifndef SRC_DRIVE_H_
#define SRC_DRIVE_H_

#include <DragonStick.h>
#include <RobotIO.h>
#include <DragonController.h>

class Drive {
private:

	RobotIO* io;
	DragonStick* driveStick;
	DragonController* dragonControlLeftVel;
	DragonController* dragonControlRightVel;
	const double leftVelKp = 0.0;
	const double rightVelKp = 0.0;
	bool isDone;
	const int invertAxis = -1;
	const double steerSensitivity = 0.95;//lower sensitivity values will make it more difficult to turn
										 //		1.0 is a standard sensitivity value, system will act as if
										 //			sensitivity is not there
										 //		reasonable range of sensitivity value is [0,2.0]
public:
	Drive(DragonStick* driver, RobotIO* rIO);
	virtual ~Drive();
	void Teleop(void);
	void TeleopTank(void);
	void DriveDistance(double distance, double velocity);
	bool IsDoneDistance();
};

#endif /* SRC_DRIVE_H_ */
