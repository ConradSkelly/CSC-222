#ifndef POINT_H
#define POINT_H

#include <string>
using namespace std;

struct Point {
    double x, y;

    Point();
    Point(double x, double y);

    Point operator+(const Point& other) const;

    string to_string() const;
};


#endif //POINT_H
