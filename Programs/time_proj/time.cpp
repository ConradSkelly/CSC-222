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
  string outputTime = to_string(time.hour) + ":" + to_string(time.minute) + ":" + to_string(time.second);
  return outputTime;
  cout << time.hour << ":" << time.minute  << ":" << time.second << endl;

}