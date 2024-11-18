#include <stdio.h>
#include <iostream>
#include "time.h"
#include <string>

using namespace std;

// struct Time {
//    int hour, minute;
//    double second;
// };

string printTime(const Time& time) {
  int hour = time.hour % 24;
  int minute = time.minute % 60;
  int second = time.second % 60;

  minute += time.second / 60;
  hour += (time.minute + (time.second / 60)) / 60;
  if (hour >= 24) {
      hour -= 24;
    }


  string outputTime = to_string(time.hour) + ":" + to_string(time.minute) + ":" + to_string(time.second);
  return outputTime;
  cout << time.hour << ":" << time.minute  << ":" << time.second << endl;
}
