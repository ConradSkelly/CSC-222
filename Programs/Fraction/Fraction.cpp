#include <string>
#include <iostream>
#include "Fraction.h"
using namespace std;

//constructors
Fraction::Fraction(){
    this -> top = 0;
    this -> bottom = 1;
}

Fraction::Fraction(int top, int bottom) {
    this -> top = top;
    this -> bottom = bottom;
}

Fraction::Fraction(string sFraction){
    this -> sFraction = sFraction;
    top = 0;
    bottom = 1;
}

Fraction Fraction::toNumber(){
    top = stoi(sFraction.substr(0,sFraction.find("/")));
    bottom = stoi(sFraction.substr(sFraction.find("/")+1));
    return Fraction(top, bottom);
}

int gcd(int numerator, int denominator) {
    int remainder = 0;
    while (denominator != 0) {
        remainder = numerator % denominator;
        numerator = denominator;
        denominator = remainder;
    }
    return numerator;
}

