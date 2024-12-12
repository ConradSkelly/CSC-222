#pragma once
#include <string>
using namespace std;

struct Fraction {
    //vars
    int top, bottom;
    string sFraction;

    //construction
    Fraction();
    Fraction(int top,int bottom);
    explicit Fraction (string sFraction);
    Fraction(int top);

    //function
    Fraction toNumber();
    string toString();
};

int gcd(int, int);