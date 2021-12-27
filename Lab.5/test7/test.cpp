#include "gtest/gtest.h"
#include "../Task_7/Task_7.cpp"

TEST(Funk, Test1) {
  EXPECT_EQ(736, Funk(1234, 1234, 10000));
}

TEST(Funk, Test2) {
    EXPECT_EQ(39087387, Funk(2323, 99999999999, 100000000));
}
TEST(Funk, Test3) {
    EXPECT_EQ(494777344, Funk(4, 99999, 1000000000));
}

TEST(Funk, Test4) {
    EXPECT_EQ(91255296, Funk(888, 888, 100000000));
}
TEST(Funk, Test5) {
    EXPECT_EQ(921859071, Funk((unsigned long long)(1e19)-1,(unsigned long long) (1e19) - 1, 1000000000));
}