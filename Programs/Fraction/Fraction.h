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

    //function
    Fraction toNumber();
    int numerator();
    int denominator();
};

int gcd(int, int);