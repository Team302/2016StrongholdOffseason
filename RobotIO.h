/*
 * RobotIO.h
 *
 *  Created on: Sep 14, 2016
 *      Author: Alex
 */

#ifndef SRC_ROBOTIO_H_
#define SRC_ROBOTIO_H_

#include "WPILib.h"

class RobotIO {
public:
	RobotIO();
	virtual ~RobotIO();

private:
	//Declaring Motors
	CANTalon* m_leftDriveMotor;
	CANTalon* m_leftDriveMotorSlave;
	CANTalon* m_rightDriveMotor;
	CANTalon* m_rightDriveMotorSlave;

	CANTalon* m_leftShooterMotor;
	CANTalon* m_rightShooterMotor;
	AnalogInput* m_shooterAngle;
	CANTalon* m_shooterPivotMotor;
	CANTalon* m_intakeWheelsMotor;
	DigitalInput* m_ballSensor;
	AnalogInput* m_airPressure;
	Solenoid* m_punchPiston;
	Solenoid* m_intakePiston;

	//create private variables for raw sensor values
	int leftDistance, rightDistance, leftVelocity, rightVelocity;
	bool ballPresent;
	double shooterAngle, airPressure;
	const double feetConv = 0.00164; //1440 counts; .00236 for 1000 counts.
	const double feetSecConv = 0.0164; //1440 counts; .0236 for 1000 counts.
	const double voltToDeg = 72.0;
	const double degOffset = -2.7;

public:
	//Declaring Functions
	void SetLeftSpeed(float Speed);
	void SetRightSpeed(float Speed);
	void SetShooterMotorSpeed(float Speed);
	void SetShooterPivotSpeed(float Speed);
	void SetIntakeSpeed(float Speed);
	void SetIntakePosition(bool position);
	void SetPunchPosition(bool position);
	void UpdateSensors();
	double GetLeftDistance();
	double GetRightDistance();
	double GetShootAngle();
	bool IsBallPresent();
	double GetLeftVel();
	double GetRightVel();
	double GetAirPressure();

	enum Value {Off, Forward, Reverse};
};


#endif /* SRC_ROBOTIO_H_ */
