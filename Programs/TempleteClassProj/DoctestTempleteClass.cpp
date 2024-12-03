#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdio.h>
#include <doctest.h>
#include "TempleteClass.h"

TEST_CASE("Testing functionality of [TempleteClass]") {
TempleteClass t1(1);
CHECK(t1.getData() == 1);
TempleteClass t2(3.14);
CHECK(t2.getData() == 3.14);
}

TEST_CASE("testing swap function") {
    TempleteClass t3(1,5);
    auto swap = t3.getPair();
    CHECK(swap.first == 5);
    CHECK(swap.second == 1);
}