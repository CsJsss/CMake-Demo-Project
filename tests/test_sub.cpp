#include "include/sub.hpp"
#include "gtest/gtest.h"

TEST(TestSubInt, test_sub_int_right) {
  int res = sub(10, 24);
  EXPECT_EQ(res, -14);
}

TEST(TestSubInt, test_sub_int_false) {
  int res = sub(10, 24);
  EXPECT_NE(res, 1234);
}