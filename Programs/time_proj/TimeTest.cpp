#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdio.h>
#include <doctest.h>
#include <vector>
#include <string>
#include "time.h"

TEST_CASE("Testing render_num_vector") {
    Time nums = {15,119,78};
    CHECK("17:0:18" == nums.print());
}

TEST_CASE("testing changing into seconds") {
    Time num = {1, 10, 14};
    double seconds = totalSeconds(num);
    CHECK( 4214 == seconds );
}

TEST_CASE("compateing time") {
    Time num = {1, 10, 14};
    Time doneTime = {10,15,45};
    doneTime.after(num);
    CHECK(doneTime.after(num) == 1);
}

TEST_CASE("seconds to total time") {
    Time num = {20000};
    CHECK("5:33:20" == num.secondToTime());
}

TEST_CASE("Test can create and render Times") {
    Time t1;
    CHECK(t1.secondToTime() == "0:00:00");
    Time t2(7);
    CHECK(t2.secondToTime() == "0:00:07");
    Time t3(72);
    CHECK(t3.secondToTime() == "0:01:12");
    Time t4(7 * 3600 + 11 * 60 + 19);
    CHECK(t4.secondToTime() == "7:11:19");
}

TEST_CASE("Test hour-minute and hour-minute-second constructors") {
    Time t1(5, 37);
    CHECK(t1.toString() == "5:37:00");
    Time t2(7, 2, 11);
    CHECK(t2.toString() == "7:02:11");
}

TEST_CASE("Test can add two Times with + operator") {
    Time t1(25, 40);
    Time t2(17, 2, 42);
    Time t3 = t1 + t2;
    CHECK(t3.toString() == "42:42:42");
}


