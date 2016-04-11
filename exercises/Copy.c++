// --------
// Copy.c++
// --------

// http://www.cplusplus.com/reference/algorithm/copy/

#include <algorithm>  // copy, equal
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

#include "Copy.h"

using namespace std;
using namespace testing;

using Copy_List_Signature = function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator)>;

struct Copy_List_Fixture : TestWithParam<Copy_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Copy_List_Instantiation,
    Copy_List_Fixture,
    Values(
           copy<list<int>::const_iterator, vector<int>::iterator>,
        my_copy<list<int>::const_iterator, vector<int>::iterator>));

TEST_P(Copy_List_Fixture, test_1) {
    const list<int>       x = {2, 3, 4};
          vector<int>     y(5);
    const vector<int>     z = {0, 2, 3, 4, 0};
    vector<int>::iterator p = GetParam()(x.begin(), x.end(), y.begin() + 1);
    ASSERT_EQ(p, y.begin() + 4);
    ASSERT_TRUE(equal(y.begin(), y.end(), z.begin()));}

TEST_P(Copy_List_Fixture, test_2) {
    const list<int>       x = {2, 3, 4, 5};
          vector<int>     y(6);
    const vector<int>     z = {0, 2, 3, 4, 5, 0};
    vector<int>::iterator p = GetParam()(x.begin(), x.end(), y.begin() + 1);
    ASSERT_EQ(p, y.begin() + 5);
    ASSERT_TRUE(equal(y.begin(), y.end(), z.begin()));}
