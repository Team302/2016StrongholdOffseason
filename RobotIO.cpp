/*
 * RobotOut.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Alex
 *      Other Author: Michael
 */

#include <RobotIO.h>
#include <WPILib.h>
#include <RobotMap.h>
RobotIO::RobotIO()
{

	//Initialization of Drive motors
	m_leftDriveMotor = new CANTalon(LEFT_DRIVE_MOTOR);
	m_leftDriveMotorSlave = new CANTalon(LEFT_DRIVE_MOTOR_SLAVE);
	m_rightDriveMotor = new CANTalon(RIGHT_DRIVE_MOTOR);
	m_rightDriveMotorSlave = new CANTalon(RIGHT_DRIVE_MOTOR_SLAVE);

	//Initialize Shooter Motors and Pistons
	m_leftShooterMotor = new CANTalon(LEFT_SHOOTER_MOTOR);
	m_rightShooterMotor = new CANTalon(RIGHT_SHOOTER_MOTOR);
	m_shooterPivotMotor = new CANTalon(SHOOTER_PIVOT_MOTOR);
	m_punchPiston = new Solenoid(PUNCH_SOLENOID_CHANNEL_A);


	//Initialize Shooter Sensor
	m_shooterAngle = new AnalogInput(SHOOTER_PIVOT_ANGLE_SENSOR);

	//Initialize Intake Motors and Pistons
	m_intakeWheelsMotor = new CANTalon(INTAKE_WHEELS_MOTOR);
	m_intakePiston = new Solenoid(INTAKE_SOLENOID_CHANNEL_A);

	//Initialize Intake Sensors
	m_ballSensor = new DigitalInput(INTAKE_BALL_SENSOR);

	//Initialize pressure sensor
	m_airPressure = new AnalogInput(ANALOG_INPUT_VIA_AIR_PRESSURE);

	//initialize sensor values
	leftDistance = 0;
	rightDistance = 0;
	leftVelocity = 0;
	rightVelocity = 0;
	ballPresent = false;
	shooterAngle = 0.0;
	airPressure = 0.0;

	//Invert left side motors
	m_leftDriveMotor->SetInverted(true);
	m_leftDriveMotorSlave->SetInverted(true);
}

/*SetLeftSpeed
 *Sends a value -1 to 1 to left side motors
 *@param float speed
 */
void RobotIO::SetLeftSpeed(float speed)
{
	m_leftDriveMotor->Set(speed);
	m_leftDriveMotorSlave->Set(speed);
}

/*SetRightSpeed
 *Sends a value -1 to 1 to right side motors
 *@param float speed
 */
void RobotIO::SetRightSpeed(float speed)
{
	m_rightDriveMotor->Set(speed);
	m_rightDriveMotorSlave->Set(speed);
}

/*SetShooterMotorSpeed
 *Sends a value -1 to 1 to both shooter  motors
 *@param float speed
 */
void RobotIO::SetShooterMotorSpeed(float speed)
{
	m_leftShooterMotor->Set(speed);
	m_rightShooterMotor->Set(-speed);
}

/*SetShooterPivotSpeed
 *Sends a value -1 to 1 to shooter pivot motor
 *@param float speed
 */
void RobotIO::SetShooterPivotSpeed(float speed)
{
	m_shooterPivotMotor->Set(speed);
}

/*SetIntakeSpeed
 *Sends a value -1 to 1 to intake motor
 *@param float speed
 */
void RobotIO::SetIntakeSpeed(float speed)
{
	m_intakeWheelsMotor->Set(speed);
}

/*SetIntakePosition
 *Sends a value of forward or reverse to the Intake Solenoid
 *
 */
void RobotIO::SetIntakePosition(bool position)
{

		m_intakePiston -> Set(position);

}

/*SetIntakePosition
 *Sends a value of forward or reverse to the Intake Solenoid
 *
 */
void RobotIO::SetPunchPosition(bool position)
{
	m_punchPiston -> Set(position);

}

/*GetLeftDistance
 *returns the distance of the left encoder in ft
 *
 */
double RobotIO::GetLeftDistance()
{
	return (double) (leftDistance * feetConv);
}

/*GetRightDistance
 *returns the distance of the right encoder in ft
 *
 */
double RobotIO::GetRightDistance()
{
	return (double) (rightDistance * feetConv);
}

/*GetShootAngle
 *returns the angle of the shooter in degrees
 *
 */
double RobotIO::GetShootAngle()
{
	return (double) ((shooterAngle * voltToDeg) + degOffset);
}

/*IsBallPresent
 *returns true when the ball is present
 *
 */
bool RobotIO::IsBallPresent()
{

	return ballPresent;
}

/*GetLeftVel
 *returns the velocity of the left drive wheels in ft/s
 *
 */
double RobotIO::GetLeftVel()
{

	return (double) (leftVelocity * feetSecConv);
}

/*GetRightVel
 *returns the velocity of the right drive wheels in ft/s
 *
 */
double RobotIO::GetRightVel()
{

	return (double) (rightVelocity * feetSecConv);
}

/*GetAirPressure
 *returns the air pressure of the robot
 *
 */
double RobotIO::GetAirPressure()
{
	return airPressure;
}

/*UpdateSensors
 *Updates the values of the sensors
 *
 */
void RobotIO::UpdateSensors()
{
	leftDistance = m_leftDriveMotor -> GetPosition();
	rightDistance = m_rightDriveMotor -> GetPosition();
	shooterAngle = m_shooterAngle -> GetVoltage();
	ballPresent = m_ballSensor -> Get();
	leftVelocity = m_rightDriveMotor -> GetEncVel();
	rightVelocity = m_leftDriveMotor -> GetEncVel();
	airPressure = m_airPressure -> GetVoltage();

}

RobotIO::~RobotIO() {
	// TODO Auto-generated destructor stub
}

