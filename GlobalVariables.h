#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include "HourTimer.h"
#include "DefaultValues.h"




namespace Global {


  	extern HourTimer timeBetweenWatering;
  	extern HourTimer timeWatering;
  
  	extern unsigned int countUpTo1Second;


  	bool setUpGlobalVariables(void);


	 void updateAllHourTimers(void);
  
}

#endif //GLOBAL_VARIABLES_H
