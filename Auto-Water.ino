


enum WateringState {IDLING, WATERING, WATER_LOW}
WateringState currentState;

void setup() {
  // put your setup code here, to run once:

  currentState = IDLING;

}



void loop() {
  
  //!
  //! 1. Perform update functions as necassary. 
  //!
  
  
  //!
  //! 2. Enter state machine.
  //!
  switch (currentState) {
    case IDLING:
    {
      
      
      
      
    }
    break;
    
    case WATER_LOW:
    {
      
      
      
      
      
    }
    break;
  
    case WATERING:
    {
      
      
      
      
    }
    break;
    
  }
  
  
  // put your main code here, to run repeatedly:

}
