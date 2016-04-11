// ------------------
// DigitsIterator.c++
// ------------------

#include <algorithm> // equal
#include <list>      // list

#include "gtest/gtest.h"

#include "DigitsIterator.h"

using namespace std;

TEST(Digits_Iterator_Fixture, test_1) {
    const Digits_Iterator<int> b = 0;
    const Digits_Iterator<int> e = 0;
    ASSERT_EQ(b, e);}

TEST(Digits_Iterator_Fixture, test_2) {
    Digits_Iterator<int> b = 2;
    Digits_Iterator<int> e = 0;
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    Digits_Iterator<int>& x = ++b;
    ASSERT_EQ(&x, &b);
    ASSERT_EQ(b, e);}

TEST(Digits_Iterator_Fixture, test_3) {
    Digits_Iterator<int> b = 23;
    Digits_Iterator<int> e = 0;
    ASSERT_NE(b, e);
    ASSERT_EQ(3, *b);
    ++b;
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    b++;
    ASSERT_EQ(b, e);}

TEST(Digits_Iterator_Fixture, test_4) {
    Digits_Iterator<int> b = 234;
    Digits_Iterator<int> e = 0;
    list<int>            x = {4, 3, 2};
    ASSERT_TRUE(equal(b, e, x.begin()));}

/*
% g++ -pedantic -std=c++11 -Wall DigitsIterator.c++ -o DigitsIterator -lgtest_main



% DigitsIterator
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Digits_Iterator_Fixture
[ RUN      ] Digits_Iterator_Fixture.test_1
[       OK ] Digits_Iterator_Fixture.test_1 (0 ms)
[ RUN      ] Digits_Iterator_Fixture.test_2
[       OK ] Digits_Iterator_Fixture.test_2 (0 ms)
[ RUN      ] Digits_Iterator_Fixture.test_3
[       OK ] Digits_Iterator_Fixture.test_3 (1 ms)
[ RUN      ] Digits_Iterator_Fixture.test_4
[       OK ] Digits_Iterator_Fixture.test_4 (0 ms)
[----------] 4 tests from Digits_Iterator_Fixture (1 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 4 tests.
*/
