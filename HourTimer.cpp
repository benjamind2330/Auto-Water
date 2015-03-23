#include "HourTimer.h"


HourTimer::HourTimer() : seconds_(0), targetSeconds_(0) {
}

void HourTimer::update() {
    seconds_++;
}

void HourTimer::reset() {
  seconds = 0;
}

bool HourTimer::timeReached() {
  if (seconds_ >= targetSeconds_) {
    return true;
  }
  return false;
}

void HourTimer::setTargetTime(unsigned int hours, unsigned int minutes, unsigned int seconds) {
  targetSeconds_ = hours*DefaultValue::MinutesInHour*DefaultValue::SecondsInMinute + minutes*DefaultValue::SecondsInMinute + seconds;
}
    
void HourTimer::setTargetTime(unsigned int seconds) {
  targetSeconds_ = seconds;
}
