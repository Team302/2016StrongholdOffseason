/*
 * DragonController.h
 *
 *  Created on: Sep 15, 2016
 *      Author: Elite
 */

#ifndef SRC_DRAGONCONTROLLER_H_
#define SRC_DRAGONCONTROLLER_H_

class DragonController {
public:
	DragonController();
	virtual ~DragonController();
	double PControl(double currentVal, double targetVal, double Kp);
};

#endif /* SRC_DRAGONCONTROLLER_H_ */
