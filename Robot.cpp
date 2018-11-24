#include "WPILib.h"
#include <RobotIO.h>
#include <DragonStick.h>
#include <Drive.h>
#include <Mechanism.h>
#include <RobotMap.h>
#include <AutonDriver.h>

class Robot: public IterativeRobot
{
private:
	LiveWindow* lw = LiveWindow::GetInstance();
	SendableChooser* chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
	Compressor* comp;
	RobotIO* rIO;
	DragonStick* driverStick;
	DragonStick* operatorStick;
	Drive* robotDrive;
	Mechanism* robotScore;
	AutonDriver* auton;
	CANTalon* m_aimingLight;
	int autoLoopCount = 0;

	void RobotInit()
	{
		chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);

		//init classes
		comp = new Compressor(0);
		rIO = new RobotIO();
		driverStick = new DragonStick(DRIVER_CONTROLLER);
		operatorStick = new DragonStick(OPERATOR_CONTROLLER);
		robotDrive = new Drive(driverStick, rIO);
		robotScore = new Mechanism(operatorStick, rIO);
		auton = new AutonDriver(robotDrive, robotScore, rIO);
		m_aimingLight = new CANTalon(SHOOTER_AIMING_LIGHT);
		m_aimingLight->Set(1.0);




		//start closed loop compressor control
		comp->Start();
	}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit()
	{
		autoLoopCount = 0;


		rIO->SetPunchPosition(false);
		rIO -> UpdateSensors();
		autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
	}

	void AutonomousPeriodic()
	{
		double leftDistance = rIO->GetLeftDistance();
		double rightDistance = rIO->GetRightDistance();
		SmartDashboard::PutNumber("LeftDistance",leftDistance);
		SmartDashboard::PutNumber("RightDistance",rightDistance);


		rIO -> UpdateSensors();
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
				auton->LowBarAuton();
		} else {
			//Default Auto goes here
				if(autoLoopCount < 100) //auton->ForwardAuton(0.0,0.0);
				{
					rIO->SetLeftSpeed(.65);
					rIO->SetRightSpeed(.65);
				}
				else
				{
					rIO->SetLeftSpeed(0.0);
					rIO->SetRightSpeed(0.0);
				}
		}


		autoLoopCount ++;
	}

	void TeleopInit()
	{
		rIO->SetPunchPosition(false);
		rIO -> UpdateSensors();
	}

	void TeleopPeriodic()
	{
		rIO -> UpdateSensors();
		robotDrive -> Teleop();
		robotScore -> Teleop();

		SmartDashboard::PutNumber("sensor", rIO->GetShootAngle());

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
