/*
 * Mechanism.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Alex
 */

#include <Mechanism.h>
#include <RobotIO.h>
#include <DragonStick.h>

Mechanism::Mechanism(DragonStick* coPilot, RobotIO* rIO)
{
	opController = coPilot;
	io = rIO;
	intakeUp = false;
	intakeDown = false;
	wheelsOut = false;
	spinShooter = false;
	punchBall = false;
	aimHigh = false;
	prevIntakeUp = false;
	prevIntakeDown = false;
	prevAimHigh = false;
	intakePosition = false; // change to true to default the intake to the up position, after checking pneumatics
	m_overrideShootLimit = false;	// JW
	m_spinLowgoalShooter = false;	//JW

}

void Mechanism::Teleop()
{
	float shooterNudge, shooterSpeed, intakeWheelSpeed;
	double shooterActualAngle;
	bool moveIntakeUp, moveIntakeDown;
	bool punchState;
	shooterActualAngle = io->GetShootAngle();
	shooterNudge = opController -> GetRawAxis(AXIS_SHOOTER_NUDGE);
	intakeUp = opController ->GetRawButton(B_INTAKE_UP);
	intakeDown = opController ->GetRawButton(B_INTAKE_DOWN);
	wheelsOut = opController ->GetRawButton(B_INTAKE_WHEELS_OUT);
	spinShooter = opController ->GetRawButton(B_SPIN_SHOOTER_WHEELS);
	punchBall = opController ->GetRawButton(B_PUNCH_BALL);
	aimHigh = opController ->GetRawButton(B_AIM_SHOOTER);
	m_overrideShootLimit = opController ->GetRawButton(B_OVERRIDE_AIM_SHOOTER_LIMIT); // JW
	m_spinLowgoalShooter = opController ->GetRawButton(B_LOWGOAL_SPIN_SHOOTER_WHEELS); // JW


	//spin shooter wheels
	if(spinShooter)
	{
		shooterSpeed = shootingSpeed; //run shooter wheels at preset speed
	}
	else if ( m_spinLowgoalShooter )
	{
		shooterSpeed = lowgoalShootingSpeed;
	}
	else
	{
		shooterSpeed = 0;			//stop shooter wheels
	}

	if(punchBall){
		punchState = true;
	}
	else{
		punchState = false;
	}

	//Set Intake Position
	moveIntakeDown = intakeDown && (intakeDown != prevIntakeDown); //checks if the intakeDown button was pressed
	moveIntakeUp = intakeUp && (intakeUp != prevIntakeUp); //checks if the intakeUp button was pressed

	if(moveIntakeDown)
	{
		intakePosition = true; //if button was pressed change the value of intake position to false (down)
	}
	if(moveIntakeUp)
	{
		intakePosition = false; //if button was pressed change the value of intake position to true (up)
	}

	if(intakePosition) intakeWheelSpeed = 1.0;
	else intakeWheelSpeed = 0;

	if ( !m_overrideShootLimit )	// JW
	{
		if(shooterActualAngle <= 0.5)
		{
			shooterNudge = LimitRange(shooterNudge,-1,0);
		}
		if(shooterActualAngle >= 65)
		{
			shooterNudge = LimitRange(shooterNudge,0,1);
		}
	}
	//Set Motor and Pistons
	io->SetShooterMotorSpeed(shooterSpeed);
	io->SetIntakePosition(intakePosition);
	io->SetPunchPosition(punchState);
	io->SetIntakeSpeed(intakeWheelSpeed);
	io->SetShooterPivotSpeed(shooterNudge * 0.5);
	//store previous values for next iteration
	prevIntakeUp = intakeUp;
	prevIntakeDown = intakeDown;
	prevAimHigh = aimHigh;

}
/*LimitRange
  * checks if input is in range and returns a value between the limits given
  *
  */
 float Mechanism::LimitRange(float input, float lowerLimit, float upperLimit)
 {
	 //check limits
	 bool less = input < lowerLimit;
	 bool greater = input > upperLimit;

	 float output = input; //default output to input, assume input is good until proven otherwise

	 if(less)
	 {
		 output = lowerLimit; //floor output to lowerlimit

	 }
	 if(greater)
	 {
		 output = upperLimit; //ceiling output to upperlimit
	 }

	 return output;
 }


Mechanism::~Mechanism()
{
	// TODO Auto-generated destructor stub
}

