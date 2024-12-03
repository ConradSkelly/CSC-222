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

    TempleteClass t4(1.5,5.3);
    auto swap2 = t4.getPair();
    CHECK(swap2.first == 5.3);
    CHECK(swap2.second == 1.5);

    TempleteClass t5("world","Hello");
    auto swap3 = t5.getPair();
    CHECK(swap3.first == "Hello");
    CHECK(swap3.second == "world");
}