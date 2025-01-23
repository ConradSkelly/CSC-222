#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include <doctest.h>
#include "Connect4.h"
/*
TEST_CASE("Test can create Fractions using two constructors") {
    Connect4 f1({
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'},
            {'0','0','0','0','0','0','0'}}
            );
    CHECK(f1.to_string() == "\n0000000\n0000000\n0000000\n0000000\n0000000\n0000000\n");
    Connect4 f2({
               {'0','0','0','0','0','0','0'},
               {'0','0','0','0','0','0','0'},
               {'0','0','0','0','0','0','0'},
               {'0','0','0','0','0','0','0'},
               {'0','0','0','0','0','0','0'},
               {'X','O','0','0','0','0','0'}}
               );
    CHECK(f2.to_string() == "\n0000000\n0000000\n0000000\n0000000\n0000000\nXO00000\n");
}
*/
TEST_CASE("testing human input") {
    /*
    Connect4 f3({
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'}}
        );
    CHECK(f3.MakeMove() == "\n0000000\n0000000\n0000000\n0000000\n0000000\nX000000\n"); // assuming input of one

    Connect4 f4({
       {'0','0','0','0','0','0','0'},
       {'0','0','0','0','0','0','0'},
       {'0','0','0','0','0','0','0'},
       {'0','0','0','0','0','0','0'},
       {'0','0','0','0','0','0','0'},
       {'0','0','0','0','0','0','0'}}
       );
    CHECK(f4.MakeMove() == "\n0000000\n0000000\n0000000\n0000000\n0000000\n0X00000\n"); */  // assuming imput of two
    Connect4 f5({
      {'0','0','0','0','0','0','0'},
      {'0','0','0','0','0','0','0'},
      {'0','0','0','0','0','0','0'},
      {'0','0','0','0','0','0','0'},
      {'0','0','0','0','0','0','0'},
      {'O','0','0','0','0','0','0'}}
      );
    CHECK(f5.MakeMove() == "\n0000000\n0000000\n0000000\n0000000\nX000000\nO000000\n"); // assuming imput of one
}
