#include <DragonStick.h>
#include "WPILib.h"
#include "cmath"

//Constructors
DragonStick::DragonStick(uint32_t port):Joystick(port), m_scale(1.0)
{
}

DragonStick::DragonStick(uint32_t port, float scale):Joystick(port), m_scale(scale)
{
}

//Override GetRawAxis
float DragonStick::GetRawAxis(uint32_t axis) const
{
	float output = Joystick::GetRawAxis(axis);             //Get original value from joystick
		if(std::abs(output) < DragonStick::m_DEAD_BAND_THRESH) //Check if the joystick value is within the dead band threshold
		{
			output = 0.0;
		}
		output *= m_scale;            //Multiply output by m_scale
		return output;
}

//Cube axis
float DragonStick::GetCubedAxis(uint32_t axis)
{
	float output = Joystick::GetRawAxis(axis);             //Get original value from joystick
	if(std::abs(output) < DragonStick::m_DEAD_BAND_THRESH) //Check if the joystick value is within the dead band threshold
	{
		output = 0.0;
	}
	output = std::pow(output, 3); //Cube output
	output *= m_scale;            //Multiply output by m_scale
	return output;
}


