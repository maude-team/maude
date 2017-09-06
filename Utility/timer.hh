//
//      Class for timers.
//
#ifndef _timer_hh_
#define _timer_hh_
#ifdef __GNUG__
#pragma interface
#endif
#include <sys/time.h>

class Timer
{
public:
  Timer(bool startRunning = false);
  
  bool getTimes(Int64& real, Int64& virt, Int64& prof) const;
  bool isRunning() const;
  void start();
  void stop();

private:
  enum Constants
  {
    CYCLE_LENGTH = 10000000  // length of timer cycle in seconds
  };

  static void startOsTimers();
  static Int64 calculateMicroseconds(const itimerval& startTime,
				     const itimerval& stopTime);
  
  static bool osTimersStarted;

  Int64 realAcc;
  Int64 virtAcc;
  Int64 profAcc;
  itimerval realStartTime;
  itimerval virtStartTime;
  itimerval profStartTime;
  bool running;
  bool valid;
};

inline bool
Timer::isRunning() const
{
  return running;
}

#endif
