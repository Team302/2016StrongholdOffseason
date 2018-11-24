/*
 * DragonStick.h
 *
 *  Created on: Sep 14, 2016
 *      Author: Jonah
 */
#include "WPILib.h"

//Button declarations
#define B_INTAKE_UP             1
#define B_INTAKE_DOWN           2
#define B_INTAKE_WHEELS_OUT     3
#define B_SPIN_SHOOTER_WHEELS   4
#define B_PUNCH_BALL            5
#define B_AIM_SHOOTER           6
#define B_OVERRIDE_AIM_SHOOTER_LIMIT	3	//JW - TODO need real button id
#define B_LOWGOAL_SPIN_SHOOTER_WHEELS	6	//JW - TODO need real button id

#define B_HOLD_POSITION			1
#define AXIS_SHOOTER_NUDGE		1
#define AXIS_DRIVER_THROTTLE	1
#define AXIS_DRIVER_STEER		4
#define AXIS_DRIVER_RIGHTSTICK	5
#ifndef SRC_DRAGONSTICK_H_
#define SRC_DRAGONSTICK_H_

class DragonStick: public Joystick {
private:
	const float m_DEAD_BAND_THRESH = 0.1; //changed from 0.08 to 0.1
	float m_scale;

public:
	DragonStick(uint32_t port);
	DragonStick(uint32_t port, float scale);
	~DragonStick() = default;
	float GetCubedAxis(uint32_t axis);
	float GetRawAxis(uint32_t axis) const override;

/*	//Button definitions
	const int B_INTAKE_UP           = 1;
	const int B_INTAKE_DOWN         = 2;
	const int B_INTAKE_WHEELS_OUT   = 3;
	const int B_SPIN_SHOOTER_WHEELS = 4;
	const int B_PUNCH_BALL          = 5;
	const int B_AIM_SHOOTER         = 6;*/
};



#endif /* SRC_DRAGONSTICK_H_ */
