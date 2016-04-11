// ---------
// Equal.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/equal/

#include <algorithm>  // equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

#include "Equal.h"

using namespace std;
using namespace testing;

using Equal_List_Signature = function<bool (list<int>::const_iterator, list<int>::const_iterator, vector<int>::const_iterator)>;

struct Equal_List_Fixture : TestWithParam<Equal_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Equal_List_Instantiation,
    Equal_List_Fixture,
    Values(
           equal<list<int>::const_iterator, vector<int>::const_iterator>,
        my_equal<list<int>::const_iterator, vector<int>::const_iterator>));

TEST_P(Equal_List_Fixture, test_1) {
    const list<int>   x = {2, 3, 4};
    const vector<int> y = {0, 2, 3, 4, 0};
	ASSERT_FALSE(GetParam()(x.begin(), x.end(), y.begin()));}

TEST_P(Equal_List_Fixture, test_2) {
    const list<int>   x = {2, 3, 4};
    const vector<int> y = {0, 2, 3, 4, 0};
	ASSERT_TRUE(GetParam()(x.begin(), x.end(), y.begin() + 1));}
