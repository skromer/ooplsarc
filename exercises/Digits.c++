// ---------
// Digits.c++
// ---------

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list

#include "gtest/gtest.h"

#include "Digits.h"

using namespace std;

TEST(Digits_Fixture, test_1) {
    const Digits<int>           x = 0;
    const Digits<int>::iterator b = x.begin();
    const Digits<int>::iterator e = x.end();
    ASSERT_EQ(b, e);}

TEST(Digits_Fixture, test_2) {
    Digits<int>           x = 2;
    Digits<int>::iterator b = x.begin();
    Digits<int>::iterator e = x.end();
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    Digits<int>::iterator& y = ++b;
    ASSERT_EQ(&y, &b);
    ASSERT_EQ(b, e);}

TEST(Digits_Fixture, test_3) {
    Digits<int>           x = 23;
    Digits<int>::iterator b = x.begin();
    Digits<int>::iterator e = x.end();
    ASSERT_NE(b, e);
    ASSERT_EQ(3, *b);
    ++b;
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    b++;
    ASSERT_EQ(b, e);}

TEST(Digits_Fixture, test_4) {
    Digits<int>           x = 234;
    Digits<int>::iterator b = x.begin();
    Digits<int>::iterator e = x.end();
    list<int>             y = {4, 3, 2};
    ASSERT_TRUE(equal(b, e, y.begin()));}

/*
% g++ -pedantic -std=c++11 -Wall Digits.c++ -o Digits -lgtest_main



% Digits
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Digits_Fixture
[ RUN      ] Digits_Fixture.test_1
[       OK ] Digits_Fixture.test_1 (0 ms)
[ RUN      ] Digits_Fixture.test_2
[       OK ] Digits_Fixture.test_2 (0 ms)
[ RUN      ] Digits_Fixture.test_3
[       OK ] Digits_Fixture.test_3 (0 ms)
[ RUN      ] Digits_Fixture.test_4
[       OK ] Digits_Fixture.test_4 (0 ms)
[----------] 4 tests from Digits_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/
