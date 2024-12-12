#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include <doctest.h>
#include "Fraction.h"
using namespace std;

TEST_CASE("Test can create Fractions using two constructors") {
    Fraction f1;
    CHECK(f1.top == 0);
    CHECK(f1.bottom == 1);
    Fraction f2(3, 4);
    CHECK(f2.top== 3);
    CHECK(f2.bottom == 4);
}

TEST_CASE("Test third Fraction constructor using a string") {
    Fraction f1("3/4");
    f1.toNumber();
    CHECK(f1.top == 3);
    CHECK(f1.bottom == 4);
    Fraction f2("37/149");
    f2.toNumber();
    CHECK(f2.top == 37);
    CHECK(f2.bottom == 149);
}