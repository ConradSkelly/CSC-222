#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stdio.h>
#include <doctest.h>
#include "TempleteClass.h"
#include <vector>

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

TEST_CASE("test bubble sort funtion") {
    TempleteClass<int> t1({1,7,2,20});
    std::vector<int> expected = {1, 2, 7, 20};
    CHECK(t1.bubbleSort() == expected);

    TempleteClass<std::string> t2({"apple","pear","banana","orange"});
    std::vector<std::string> strings {"apple", "banana", "orange", "pear"};
    CHECK(t2.bubbleSort() == strings);
}

TEST_CASE("test merge sort funtion") {
    TempleteClass<int> t1{{1,7,2,20,10,8,2,5,6,8,9}};
    std::vector<int> expected{{1, 2, 2, 5, 6, 7, 8, 8, 9, 10, 20}};
    CHECK(t1.mergeSort() == expected);
}