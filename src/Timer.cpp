// ************************************************
// File:    Timer.cpp
// Author:  Daniel Guenther
// Date:    2016-02-29
// Class:   CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: 
//    allows for delayed events
// ************************************************
#include <sys/time.h>
#include <cstddef>
#include "../hdr/Timer.h"
using namespace std;

// updates timer to current time
void Timer::set()
{
   struct timeval tp;
   gettimeofday(&tp, NULL);
   m_timeSinceSet = tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

// returns true if t milliseconds have elapsed since last set
// NOTE: returns true if never set()
bool Timer::elapsed(int t)
{
   // get current time
   struct timeval tp;
   gettimeofday(&tp, NULL);
   long int curtime = tp.tv_sec * 1000 + tp.tv_usec / 1000;
   // return true if the difference between last setting is larger than t
   return curtime - m_timeSinceSet > t;
}
