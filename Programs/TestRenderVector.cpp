#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "RenderNumberVectors.h"
using namespace std;

TEST_CASE("Testing render_num_vector") {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected1 = "1 3 7";
    CHECK(numstr == expected1);

    vector<int> nums2 = {1, 2, 3, 4};
    string numstr2 = render_num_vector(nums2);
    string expected2 = "1 2 3 4";
    CHECK(numstr2 == expected2);

    vector<int> nums3 = {};
    string numstr3 = render_num_vector(nums3);
    string expected3 = "";
    CHECK(numstr3 == expected3);
}

TEST_CASE("Testing num_vector_sum") {
    vector<int> nums = {1, 3, 7};
    CHECK(11 == num_vector_sum(nums));
}

TEST_CASE("Testing num_vector_product") {
    vector<int> nums = {2, 3, 7};
    CHECK(42 == num_vector_product(nums));
}

TEST_CASE("Testing only_evens") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_evens(nums);
    string expected = "2 4 6 8 12 14 22";
    CHECK(render_num_vector(evens) == expected);
}