#ifndef TIME_H
#define TIME_H

#include <string>
using namespace std;

struct Time {
    int hour, minute;
    int second;

    string print();
    string secondToTime();
    string toString();

    double to_seconds();

    Time operator+(Time);

    bool after(const Time &other);

    Time (int hour, int minute, int second);
    Time (int second);
    Time ();
    Time(int hour, int minute);


};

ostream& operator<<(ostream& os, const Time& t);


double totalSeconds(const Time& time);



#endif
