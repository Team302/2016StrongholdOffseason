/*
 * DragonController.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Elite
 */

#include <DragonController.h>

DragonController::DragonController()
{
	// TODO Auto-generated constructor stub
}

DragonController::~DragonController()
{
	// TODO Auto-generated destructor stub
}

/*
*This function is used as a pid controller, but only with a p term, so it's just a p controller.
*
*@param targetValue
*@param currentValue
*@param kP
*@return output
*/
double DragonController::PControl(double currentVal, double targetVal, double Kp)
{
	double output = 0.0;
	double error = 0.0;

	error = targetVal - currentVal;
	output = error * Kp;

	return output;
}
