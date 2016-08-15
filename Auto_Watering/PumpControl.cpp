#include "PumpControl.h"

#include "AFMotor.h"

namespace PumpControl {

	PumpState gPumpState = PUMP_OFF;
	AF_DCMotor *dcMotor;
	
	void initializePumpControl(void)
	{
		dcMotor = new AF_DCMotor(1);
		dcMotor->setSpeed(255);
	}


	PumpState pumpState(void)
	{
		return gPumpState;
	}

	void pumpOff(void)
	{
		dcMotor->run(RELEASE);
	}

	void pumpOn(void)
	{
		dcMotor->run(FORWARD);
	}
}
