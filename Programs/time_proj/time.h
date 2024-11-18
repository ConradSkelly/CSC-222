#ifndef TIME_H
#define TIME_H

#include <string>
using namespace std;

struct Time {
    int hour, minute;
    double second;
};


string printTime(const  Time& time);



#endif
