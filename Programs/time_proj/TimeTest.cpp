#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdio.h>
#include <doctest.h>
#include <vector>
#include <string>
#include "time.h"

TEST_CASE("Testing render_num_vector") {
    Time nums = {15, 119, 78};
    CHECK("17:0:18" == nums.print());
}

TEST_CASE("testing changing into seconds") {
    Time num = {1, 10, 14};
    double seconds = totalSeconds(num);
    CHECK( 4214 == seconds );
}

TEST_CASE("compateing time") {
    Time num = {1, 10, 14};
    Time doneTime {10,15,45};
    doneTime.after(num);
    CHECK(doneTime.after(num) == 1);
}


