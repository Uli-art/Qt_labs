#include "gtest/gtest.h"
#include "../Task_8/Task_8.cpp"

TEST(GreatestOddDivisor, Test1) {
    EXPECT_EQ(21, GreatestOddDivisor(7));
}

TEST(GreatestOddDivisor, Test2) {
    EXPECT_EQ(1, GreatestOddDivisor(1));
}

TEST(GreatestOddDivisor, Test3) {
    EXPECT_EQ(201537, GreatestOddDivisor(777));
}