#include "gtest/gtest.h"
#include "../Task_7/Task_7.cpp"

TEST(Test1, Division) {
  EXPECT_EQ(false, Division(2142433642,3));
}

TEST(Test2, Division) {
	EXPECT_EQ(false, Division(2142433642, 47));
}

TEST(Test3, Division) {
	EXPECT_EQ(true, Division(1506138481, 197));
}

TEST(Test4, Division) {
	EXPECT_EQ(true, Division(2064105063, 3));
}

