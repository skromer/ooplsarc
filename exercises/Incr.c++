// --------
// Incr.c++
// --------

// http://en.cppreference.com/w/cpp/language/operator_incdec

#include "gtest/gtest.h"

#include "Incr.h"

TEST(Incr_Fixture, test_1) {
    int i = 2;
    int j = pre_incr(i);
    ASSERT_EQ(3, i);
    ASSERT_EQ(3, j);}

TEST(Incr_Fixture, test_2) {
    int i = 2;
    int j = pre_incr(pre_incr(i));
    ASSERT_EQ(4, i);
    ASSERT_EQ(4, j);}

TEST(Incr_Fixture, test_3) {
    int i = 2;
    int j = post_incr(i);
    ASSERT_EQ(3, i);
    ASSERT_EQ(2, j);}

TEST(Incr_Fixture, test_4) {
    int i = 2;
//  post_incr(post_incr(i)); // error: no matching function for call to 'post_incr'
    ASSERT_EQ(2, i);}

/*
% g++ -pedantic -std=c++11 -Wall Incr.c++ -o Incr -lgtest_main



% Incr
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from Incr_Fixture
[ RUN      ] Incr_Fixture.test_1
[       OK ] Incr_Fixture.test_1 (0 ms)
[ RUN      ] Incr_Fixture.test_2
[       OK ] Incr_Fixture.test_2 (0 ms)
[ RUN      ] Incr_Fixture.test_3
[       OK ] Incr_Fixture.test_3 (0 ms)
[ RUN      ] Incr_Fixture.test_4
[       OK ] Incr_Fixture.test_4 (0 ms)
[----------] 4 tests from Incr_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/
