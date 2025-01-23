#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include <doctest.h>
#include "Connect4.h"

TEST_CASE("Test can create Fractions using two constructors") {
    Connect4 f1({
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '}}
        );
    CHECK(f1.to_string() == "      \n      \n      \n      \n      \n      \n      \n");
    Connect4 f2({
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' '},
        {'O','X',' ',' ',' ',' '},
        {'X','O',' ',' ',' ',' '}}
        );
    CHECK(f2.to_string() == "      \n      \n      \n      \n      \n      \n    \n");
}
