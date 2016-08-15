#ifndef PUMP_CONTROL_H
#define PUMP_CONTROL_H

namespace PumpControl {
	
	//! Enumeration to define the current pump state.
	enum PumpState {
		PUMP_ON,
		PUMP_OFF
	};

	//! Function to initialize the pump control. 
    	void initializePumpControl(void);

	//! Function to turn off the pump. 
	void pumpOff(void);

	//! Function to turn the pump on. 
	void pumpOn(void);

	//! Function to check the pump state.
	PumpState pumpState(void);

};









#endif
