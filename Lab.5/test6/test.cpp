#include "gtest/gtest.h"
#include "../Task_6/Task_6.cpp"

TEST(S, Test1) {
  EXPECT_EQ(46, S(1,10));
  EXPECT_TRUE(true);
}
TEST(S, Test2) {
    EXPECT_EQ(48, S(10, 20));
    EXPECT_TRUE(true);
}
TEST(S, Test3) {
    EXPECT_EQ(52, S(30, 40));
    EXPECT_TRUE(true);
}