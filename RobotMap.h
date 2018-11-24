/*
 * RobotMap.h
 *
 *  Created on: Sep 15, 2016
 *      Author: Alex
 */

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

#ifndef SRC_ROBOTMAP_H_
#define SRC_ROBOTMAP_H_

#include "WPILib.h"

	//==========================================================================================
    // USB CONTROLLER PORTS
    //==========================================================================================
	const int DRIVER_CONTROLLER 			= 0;
	const int OPERATOR_CONTROLLER			= 1;
    //==========================================================================================
    // CAN PORTS
    //==========================================================================================
    const int LEFT_DRIVE_MOTOR              = 1;
    const int LEFT_DRIVE_MOTOR_SLAVE        = 2;
    const int RIGHT_DRIVE_MOTOR             = 3;
    const int RIGHT_DRIVE_MOTOR_SLAVE       = 4;

    const int LEFT_SHOOTER_MOTOR            = 5;
    const int RIGHT_SHOOTER_MOTOR           = 6;

    const int SHOOTER_AIMING_LIGHT          = 7;

    const int SHOOTER_PIVOT_MOTOR           = 8;
    const int INTAKE_WHEELS_MOTOR           = 9;

    //==========================================================================================
    // PWM Output Ports
    //==========================================================================================


    //==========================================================================================
    // PNEUMATIC SOLENOID Ports
    //==========================================================================================
    const int INTAKE_SOLENOID_CHANNEL_A		= 0;
    const int INTAKE_SOLENOID_CHANNEL_B		= 1;
    const int PUNCH_SOLENOID_CHANNEL_A		= 1;
    const int PUNCH_SOLENOID_CHANNEL_B		= 3;

    //==========================================================================================
    // Analog Input Devices
    //==========================================================================================
    const int SHOOTER_PIVOT_ANGLE_SENSOR    = 0;
    const int ANALOG_INPUT_VIA_AIR_PRESSURE = 1;

    //==========================================================================================
    // Digital Input/Output PORTS
    //==========================================================================================
    //const int LEFT_INTAKE_CYLINDER_EXTEND   = 0;
    //const int LEFT_INTAKE_CYLINDER_RETRACT  = 1;
    //const int RIGHT_INTAKE_CYLINDER_EXTEND  = 2;
    //const int RIGHT_INTAKE_CYLINDER_RETRACT = 3;
    const int INTAKE_BALL_SENSOR = 0;


#endif /* SRC_ROBOTMAP_H_ */
