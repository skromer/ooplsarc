// --------
// Fill.c++
// --------

#include <algorithm>  // equal, fill
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <vector>     // vector

#include "gtest/gtest.h"

#include "Fill.h"

using namespace std;
using namespace testing;

using Fill_List_Signature = function<void (vector<int>::iterator, vector<int>::iterator, int)>;

struct Fill_List_Fixture : TestWithParam<Fill_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Fill_List_Instantiation,
    Fill_List_Fixture,
    Values(
           fill<vector<int>::iterator, int>,
        my_fill<vector<int>::iterator, int>));

TEST_P(Fill_List_Fixture, test_1) {
    const int         v = 2;
          vector<int> x(5);
    const vector<int> y = {0, 2, 2, 2, 0};
    GetParam()(x.begin() + 1, x.end() - 1, v);
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));}

TEST_P(Fill_List_Fixture, test_2) {
    const int         v = 3;
          vector<int> x(6);
    const vector<int> y = {0, 3, 3, 3, 3, 0};
    GetParam()(x.begin() + 1, x.end() - 1, v);
    ASSERT_TRUE(equal(x.begin(), x.end(), y.begin()));}
