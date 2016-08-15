#include "WaterSensorControl.h"
#include "Arduino.h"

namespace WaterLevelSensorContants {
    
  const int waterLevelSensorInputPin = 14;
  
}


void WaterLevelSensor::initWaterLevelSensor() {
  
  pinMode(WaterLevelSensorContants::waterLevelSensorInputPin, INPUT);
  
}
  
bool WaterLevelSensor::isWaterLow() {

  return digitalRead(WaterLevelSensorContants::waterLevelSensorInputPin) == HIGH;

}


