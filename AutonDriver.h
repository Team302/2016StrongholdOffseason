/*
 * AutonDriver.h
 *
 *  Created on: Sep 15, 2016
 *      Author: Alex
 */

#ifndef SRC_AUTONDRIVER_H_
#define SRC_AUTONDRIVER_H_

#include <Drive.h>
#include <Mechanism.h>
#include <RobotIO.h>

class AutonDriver {
private:
	RobotIO* m_io;
	Drive* m_drive;
	Mechanism* m_score;
public:
	AutonDriver(Drive* driveSystem, Mechanism* scoringSystem, RobotIO* rIO);
	void LowBarAuton();
	void ForwardAuton(double distance, double velocity);
	virtual ~AutonDriver();
};

#endif /* SRC_AUTONDRIVER_H_ */
