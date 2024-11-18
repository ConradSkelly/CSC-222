#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdio.h>
#include <doctest.h>
#include <vector>
#include <string>
#include "time.h"

TEST_CASE("Testing render_num_vector") {
    Time nums = {15, 119, 78};
    string orderTime = printTime(nums);
    CHECK("17:0:18" == orderTime);
}
