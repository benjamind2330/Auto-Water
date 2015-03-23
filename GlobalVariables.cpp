#include "GlobalVariables.h"


  
  HourTimer Global::timeBetweenWatering;
  HourTimer Global::timeWatering;

  unsigned int Global::countUpTo1Second;


  
  void Global::updateAllHourTimers(void) {
      timeBetweenWatering.update();
      timeWatering.update();
  }





bool Global::setUpGlobalVariables(void) {
  	
	  	// Actual Times
	  	// timeBetweenWatering.setTargetTime(DefaultValue::TimeBetweenWatering, 0, 0);
	  	// timeWatering.setTargetTime(0, DefaultValue::TimeWatering, 0);

		timeBetweenWatering.setTargetTime(0, 0, 10);
	  	timeWatering.setTargetTime(0, 0, 2);

	  	countUpTo1Second = 0;

	  	return true;

  	}
