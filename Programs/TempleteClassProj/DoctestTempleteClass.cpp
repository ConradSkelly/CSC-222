#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdio.h>
#include <doctest.h>
#include "TempleteClass.h"

TEST_CASE("Testing functionality of [TempleteClass]") {
TempleteClass<int> t1(1);
CHECK(t1.getData() == 1213);
}
