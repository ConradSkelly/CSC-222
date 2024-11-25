#include "Point.h"
#include <cstdio>

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

string Point::to_string() const {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "(%.6f, %.6f)", x, y);
    return string(buffer);
}