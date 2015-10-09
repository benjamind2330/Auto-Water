#ifndef DEFAULT_VALUE_H
#define DEFAULT_VALUE_H

namespace DefaultValue {
  
  // Time constants
  static const unsigned int MinutesInHour   = 60; 
  static const unsigned int HoursInDay      = 24;
  static const unsigned int SecondsInMinute = 60;

  // Other time variables.   
  static const unsigned int LoopRate 		= 100; //ms
  static const int 			LoopsInSecond	= LoopRate / 1000;


  // Watering Constants
  static const unsigned int TimeBetweenWatering = 6; //Hours
  static const unsigned int TimeToWaterFor = 3; // Minutes
  
  
}

#endif //DEFAULT_VALUE_H
