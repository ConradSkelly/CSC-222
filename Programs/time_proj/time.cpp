#include <stdio.h>
#include <iostream>
#include "time.h"
#include <string>

using namespace std;

string Time::print() {
  minute += second / 60; second %= 60;
  hour += minute / 60; minute %= 60;
  hour %= 24;

  minute += second / 60;
  if (minute > 59);
      minute %= 60;

  hour += (minute + (second / 60)) / 60;
  if (hour >= 24) {
      hour -= 24;
    }


  string outputTime = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
  return outputTime;
  cout << hour << ":" << minute  << ":" << second << endl;
}

double totalSeconds(const Time& time) {
  return time.second + (time.hour * 3600 + time.minute * 60);
}

bool Time::after(const Time& t2) {
  if (hour > t2.hour) return true;
  if (hour < t2.hour) return false;

  if (minute > t2.minute) return true;
  if (minute < t2.minute) return false;

  return (second > t2.second);
}
