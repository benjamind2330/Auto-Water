
#include "DefaultValues.h"
#include "GlobalVariables.h"
#include "LEDControl.h"
#include "PumpControl.h"
#include "WaterSensorControl.h"

enum WateringState { START_IDLING, IDLING, START_WATERING, WATERING, WATER_LOW };
WateringState currentState;
WateringState waterLowSavedState;

bool firstTimeInState = true;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(19200);
	Serial.println("Serial Startup Successfull.");

	currentState = START_IDLING;

	bool success = Global::setUpGlobalVariables();
	if (success) {
		Serial.println("Global Objects Initialized.");
	}
	else {
		Serial.println("Failed to initialize global objects.");
	}

	// Initialize the LED.
	LED::initialize();
	LED::clearLed();

        // Initialize the pump control.
        PumpControl::initializePumpControl();
        
        // Initialize the water level sensor.
        WaterLevelSensor::initWaterLevelSensor();
        

}



void loop() {
  
  	// Get the loop start time. 
	unsigned long timeStart = millis();
        Serial.print("Current State: ");
        Serial.println(currentState);

	//!
	//! Perform update functions as necassary. 
	//!

	// Update Hour Timers.
	Global::countUpTo1Second++;
	if (Global::countUpTo1Second == DefaultValue::LoopsInSecond) {
		Global::updateAllHourTimers();
		Global::countUpTo1Second = 0;
	}



	//!
	//! 2. Enter state machine.
	//!
	switch (currentState) {
	case START_IDLING:
	{
		LED::setLedBlue();
                PumpControl::pumpOff();
		if (firstTimeInState) {
			Serial.println("START_IDLING");
			firstTimeInState = false;
		}

		// Restart the waiting hour timer. 
		Global::timeBetweenWatering.reset();

		firstTimeInState = true;
		currentState = IDLING;
	}
	break;

	case IDLING:
	{
		LED::setLedGreen();
                PumpControl::pumpOff();
		if (firstTimeInState) {
			firstTimeInState = false;
			Serial.println("IDLING");
		}

		if (Global::timeBetweenWatering.targetTimeReached()) {
			firstTimeInState = true;
			currentState = START_WATERING;
		}

	}
	break;

	case WATER_LOW:
	{
		if (firstTimeInState) { 
                    Serial.println("WATER_LOW");
                    firstTimeInState = false;
                }
                PumpControl::pumpOff();
                
                if (!WaterLevelSensor::isWaterLow()) {
                  firstTimeInState = true;
                  currentState = waterLowSavedState;
                }
	}
	break;

	case START_WATERING:
	{
		LED::setLedRed();
		if (firstTimeInState) {
			firstTimeInState = false;
			Serial.println("START_WATERING");
		}
   
                PumpControl::pumpOn();
   
		Global::timeWatering.reset();

		currentState = WATERING;
		firstTimeInState = true;
	}
	break;

	case WATERING:
	{
		if (firstTimeInState) {
			Serial.println("WATERING");
			firstTimeInState = false;
		}

		if (Global::timeWatering.targetTimeReached()) {
			currentState = START_IDLING;
			firstTimeInState = true;
		}


	}
	break;

	}


        //!
        //! Check the water level
        //!
        if (WaterLevelSensor::isWaterLow() && currentState != WATER_LOW) {
          waterLowSavedState = currentState; 
          currentState = WATER_LOW;
          firstTimeInState = true;
        }
            
 	//!
	//! Fix the loop rate.
	//!
	unsigned long remainingTime = DefaultValue::LoopRate - (millis() - timeStart);

	if (remainingTime > DefaultValue::LoopRate) {
		remainingTime = 0;
	}

	delay(remainingTime);


}
