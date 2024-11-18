#include <stdio.h>
#include <iostream>
#include "time.h"
#include <string>

using namespace std;

string printTime(const Time& time) {
  int hour = time.hour % 24;
  int minute = time.minute % 60;
  int second = time.second % 60;

  minute += time.second / 60;
  if (minute > 59);
      minute %= 60;

  hour += (time.minute + (time.second / 60)) / 60;
  if (hour >= 24) {
      hour -= 24;
    }


  string outputTime = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
  return outputTime;
  cout << time.hour << ":" << time.minute  << ":" << time.second << endl;
}

double totalSeconds(const Time& time) {
  return time.second + (time.hour * 3600 + time.minute * 60);
}
