
#include "DefaultValues.h"
#include "GlobalVariables.h"

enum WateringState {START_IDLING, IDLING, START_WATERING, WATERING, WATER_LOW};
WateringState currentState;

 bool firstTimeInState = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  Serial.println("Serial Startup Successfull.");

  currentState = START_IDLING;

  bool success = Global::setUpGlobalVariables();
  if (success) {
    Serial.println("Global Objects Initialized.");
  } else {
    Serial.println("Failed to initialize global objects.");
  }

}



void loop() {
  
  // Get the loop start time. 
  unsigned long timeStart = millis();


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
       if (firstTimeInState) Serial.println("WATER_LOW");
      
      
      
      
    }
    break;
  
    case START_WATERING:
    {
       if (firstTimeInState) {
        firstTimeInState = false;
        Serial.println("START_WATERING");
      }

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
  //! Fix the loop rate.
  //!
  unsigned long remainingTime = DefaultValue::LoopRate - (millis() - timeStart);

  if (remainingTime > DefaultValue::LoopRate) {
    remainingTime = 0;
  }

  delay(remainingTime);



}
