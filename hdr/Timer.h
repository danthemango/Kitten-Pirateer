// ************************************************
// File:    Timer.h
// Author:  Daniel Guenther
// Date:    2016-02-29
// Class:   CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    allows for delayed events
// ************************************************

#ifndef TIMER_H
#define TIMER_H

class Timer{
   public:
      Timer():m_timeSinceSet(0), m_isSet(false){}
      // updates timer to current time
      void set();
      // returns true if t milliseconds have elapsed since last set
      // NOTE: returns true if never set()
      bool elapsed(int t);
      bool isSet();
      void unSet();
   private:
      // time in milliseconds since the last set
      long int m_timeSinceSet;
      bool m_isSet;
};

#endif // TIMER_H
