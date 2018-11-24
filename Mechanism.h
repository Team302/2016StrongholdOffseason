/*
 * Mechanism.h
 *
 *  Created on: Sep 15, 2016
 *      Author: Alex
 */

#ifndef SRC_MECHANISM_H_
#define SRC_MECHANISM_H_

#include <DragonStick.h>
#include <RobotIO.h>

class Mechanism {
private:
	DragonStick* opController;
	RobotIO* io;
	bool intakeUp, intakeDown, wheelsOut, spinShooter, punchBall, aimHigh, intakePosition;
	bool prevIntakeUp, prevIntakeDown, prevAimHigh;
	bool m_overrideShootLimit;			// jw
	bool m_spinLowgoalShooter;			// jw
	const float shootingSpeed = 1.0;
	const float lowgoalShootingSpeed = 0.6; //JW
	float LimitRange(float input,float lowerLimit, float upperLimit);

public:
	Mechanism(DragonStick* coPilot, RobotIO* rIO);
	void Teleop();
	virtual ~Mechanism();
};

#endif /* SRC_MECHANISM_H_ */
