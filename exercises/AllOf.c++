// ---------
// AllOf.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/all_of/

#include <algorithm>  // all_of
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list

#include "gtest/gtest.h"

#include "AllOf.h"

using namespace std;
using namespace testing;

using AllOf_List_Signature = function<bool (list<int>::const_iterator, list<int>::const_iterator, function<bool (int)>)>;

struct AllOf_List_Fixture : TestWithParam<AllOf_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    AllOf_List_Instantiation,
    AllOf_List_Fixture,
    Values(
           all_of<list<int>::const_iterator, function<bool (int)>>,
        my_all_of<list<int>::const_iterator, function<bool (int)>>));

TEST_P(AllOf_List_Fixture, test_1) {
    const list<int> x = {3, 5, 7};
    ASSERT_TRUE(GetParam()(x.begin(), x.end(), [] (int v) -> bool {return (v % 2);}));}

TEST_P(AllOf_List_Fixture, test_2) {
    const int       n = 2;
    const list<int> x = {3, 5, 7};
    ASSERT_TRUE(GetParam()(x.begin(), x.end(), [n] (int v) -> bool {return (v % n);}));}
