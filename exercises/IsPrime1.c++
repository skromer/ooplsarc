// ------------
// IsPrime1.c++
// ------------

// https://en.wikipedia.org/wiki/Primality_test

#include "gtest/gtest.h"

#include "IsPrime1.h"

TEST(Is_Prime_Fixture, test_1) {
    ASSERT_FALSE(is_prime( 1));}

TEST(Is_Prime_Fixture, test_2) {
    ASSERT_FALSE(is_prime( 2));}

TEST(Is_Prime_Fixture, test_3) {
    ASSERT_TRUE(is_prime( 3));}

TEST(Is_Prime_Fixture, test_4) {
    ASSERT_FALSE(is_prime( 4));}

TEST(Is_Prime_Fixture, test_5) {
    ASSERT_TRUE(is_prime( 5));}

TEST(Is_Prime_Fixture, test_7) {
    ASSERT_TRUE(is_prime( 7));}

TEST(Is_Prime_Fixture, test_9) {
    ASSERT_TRUE(is_prime( 9));}

TEST(Is_Prime_Fixture, test_27) {
    ASSERT_FALSE(is_prime(27));}

TEST(Is_Prime_Fixture, test_29) {
    ASSERT_TRUE(is_prime(29));}

/*
% g++ -pedantic -std=c++11 -Wall IsPrime1.c++ -o IsPrime1 -lgtest_main



% IsPrime1
Running main() from gtest_main.cc
[==========] Running 9 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 9 tests from Is_Prime_Fixture
[ RUN      ] Is_Prime_Fixture.test_1
[       OK ] Is_Prime_Fixture.test_1 (0 ms)
[ RUN      ] Is_Prime_Fixture.test_2
[       OK ] Is_Prime_Fixture.test_2 (0 ms)
[ RUN      ] Is_Prime_Fixture.test_3
[       OK ] Is_Prime_Fixture.test_3 (0 ms)
[ RUN      ] Is_Prime_Fixture.test_4
[       OK ] Is_Prime_Fixture.test_4 (0 ms)
[ RUN      ] Is_Prime_Fixture.test_5
[       OK ] Is_Prime_Fixture.test_5 (0 ms)
[ RUN      ] Is_Prime_Fixture.test_7
[       OK ] Is_Prime_Fixture.test_7 (0 ms)
[ RUN      ] Is_Prime_Fixture.test_9
[       OK ] Is_Prime_Fixture.test_9 (0 ms)
[ RUN      ] Is_Prime_Fixture.test_27
[       OK ] Is_Prime_Fixture.test_27 (0 ms)
[ RUN      ] Is_Prime_Fixture.test_29
[       OK ] Is_Prime_Fixture.test_29 (0 ms)
[----------] 9 tests from Is_Prime_Fixture (0 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 9 tests.
*/
