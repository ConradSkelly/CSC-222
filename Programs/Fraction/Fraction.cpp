#include <string>
#include <iostream>
#include "Fraction.h"
using namespace std;

//constructors
Fraction::Fraction(){
    this -> top = 0;
    this -> bottom = 1;
}

Fraction::Fraction(int top){
  this -> top = top;
  bottom = 1;
}

Fraction::Fraction(int top, int bottom) {
    int divisor = gcd(top, bottom);
    this->top = top / divisor;
    this->bottom = bottom / divisor;
}

Fraction::Fraction(string sFraction){

    if (sFraction.find("/") == -1)  {
        top = stoi(sFraction);
        bottom = 1;
        }
    else {
    this -> sFraction = sFraction;
    top = 0;
    bottom = 1;
    }
}

Fraction Fraction::toNumber(){
    top = stoi(sFraction.substr(0,sFraction.find("/")));
    bottom = stoi(sFraction.substr(sFraction.find("/")+1));
    return Fraction(top, bottom);
}

string Fraction::toString() {
    if (bottom == 1)
        return to_string(top);
    return to_string(top) + "/" + to_string(bottom);
}

int gcd(int top, int bottom) {
    int remainder = 0;
    while (bottom != 0) {
        remainder = top % bottom;
        top = bottom;
        bottom = remainder;
    }
    return top;
}

