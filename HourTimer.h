#ifndef HOUR_TIMER_H
#define HOUR_TIMER_H

class HourTimer {
  
  public:
    //!
    //! Default constructor.
    //!
    HourTimer();
  
    //! 
    //! Update function, this must be called once per second. 
    //!
    void update();
    
    //!
    //! Reset function, this will be called to reset the timer. 
    //!
    void reset();
    
    //!
    //! Check if the set target time has been reached. 
    //! 
    //! @return True if target time reached, False otherwise.
    //!
    bool targetTimeReached();
    
    //!
    //! Function to set the target time for the timer.
    //!
    //! @param hours     Target number of hours.
    //! @param minutes   Target number of minutes.
    //! @param seconds   Target number of seconds.
    //!
    void setTargetTime(unsigned int hours, unsigned int minutes, unsigned int seconds);
    
    //!
    //! Function to set the target time for the timer.
    //!
    //! @param seconds   Target number of seconds.
    //!
    void setTargetTime(unsigned int seconds);
  
  private:
  
    unsigned long seconds_; // Current seconds since previous reset.
    unsigned long targetSeconds_; // Target seconds. 
  
};

#endif //HOUR_TIMER_H
