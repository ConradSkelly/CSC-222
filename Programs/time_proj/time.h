#ifndef TIME_H
#define TIME_H

#include <string>
using namespace std;

struct Time {
    int hour, minute;
    int second;
};


string printTime(const  Time& time);

double totalSeconds(const Time& time);



#endif
