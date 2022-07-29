#include "include/add.hpp"
#include "gtest/gtest.h"

TEST(TestAddInt, test_add_int_right) {
  int res = add(10, 24);
  EXPECT_EQ(res, 34);
}

TEST(TestAddInt, test_add_int_false) {
  int res = add(10, 24);
  EXPECT_NE(res, 1234);
}