#include "gtest/gtest.h"
#include "../Task_8/Task_8.cpp"

TEST(Test1, Decimal) {
  EXPECT_EQ("1", Decimal(1));
}

TEST(Test2, Decimal) {
	EXPECT_EQ("10", Decimal(2));
}

TEST(Test3, Decimal) {
	EXPECT_EQ("1100", Decimal(10));
}

TEST(Test4, Decimal) {
	EXPECT_EQ("111000000", Decimal(50));
}
//11101011000000
TEST(Test5, Decimal) {
	EXPECT_EQ("1010000000000", Decimal(100));
}
TEST(Test6, Decimal) {
	EXPECT_EQ("11101011000000", Decimal(150));
}