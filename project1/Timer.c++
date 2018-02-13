
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#ifndef TIMER_H
#define TIMER_H

class Timer
{
  public:

    void start()
    {
      gettimeofday(&startTime, NULL);
    }

    double stop()
    {
      long seconds, nseconds;
      double duration;

      gettimeofday(&endTime, NULL);

      seconds = endTime.tv_sec - startTime.tv_sec;
      nseconds = endTime.tv_usec - startTime.tv_usec;

      duration = seconds + nseconds / 1000000.0;

      return duration;
    }

    void printTime(double duration)
    {
      printf("%5.6f seconds\n", duration);
    }

  private:
    timeval startTime;
    timeval endTime;
};

#endif
