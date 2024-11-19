#ifndef TIME_H
#define TIME_H

#include <string>
using namespace std;

struct Time {
    int hour, minute;
    int second;

    string print();
    double to_seconds();
    bool after(const Time &other);
};

double totalSeconds(const Time& time);



#endif
