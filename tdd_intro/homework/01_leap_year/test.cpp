/*
Given a year, report if it is a leap year.

The tricky thing here is that a leap year in the Gregorian calendar occurs:

on every year that is evenly divisible by 4
  except every year that is evenly divisible by 100
    unless the year is also evenly divisible by 400

For example, 1997 is not a leap year, but 1996 is. 1900 is not a leap year, but 2000 is.

If your language provides a method in the standard library that does this look-up, pretend it doesn't exist and implement it yourself.
*/

#include <gtest/gtest.h>
#include <cstdlib>
#include <climits>

const unsigned MAX_RAND_VALUE = 3000;

bool is_leap_year(unsigned year) {
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

TEST(LeapYearTest, When_MultipleToFourYear_ReturnTrue) {
    unsigned random_year = rand() % MAX_RAND_VALUE * 4;
    ASSERT_EQ(true, is_leap_year(random_year));
}

TEST(LeapYearTest, When_MultipleToOneHundredYear_ReturnFalse) {
    unsigned random_year = rand() % MAX_RAND_VALUE * 100;
    ASSERT_EQ(false, is_leap_year(random_year));
}

TEST(LeapYearTest, When_MultipleToFourHundredYear_ReturnTrue) {
    unsigned random_year = rand() % MAX_RAND_VALUE * 400;
    ASSERT_EQ(true, is_leap_year(random_year));
}
