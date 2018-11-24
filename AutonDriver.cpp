/*
 * AutonDriver.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Alex
 */

#include <AutonDriver.h>
#include <RobotIO.h>
#include <Drive.h>
#include <Mechanism.h>


AutonDriver::AutonDriver(Drive* driveSystem, Mechanism* scoringSystem, RobotIO* rIO)
{
	m_io = rIO;
	m_drive = driveSystem;
	m_score = scoringSystem;
}

void AutonDriver::LowBarAuton()
{
	//do the same as forward auton but make sure m_score is in the down position
}

void AutonDriver::ForwardAuton(double distance, double velocity)
{
	//m_drive->DriveDistance(distance, velocity);

}

AutonDriver::~AutonDriver()
{
	// TODO Auto-generated destructor stub
}

