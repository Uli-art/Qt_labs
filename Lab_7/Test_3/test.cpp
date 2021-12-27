#include "gtest/gtest.h"
#include "../Task_3/Task_3.cpp"

TEST(Test1, Sum) {
  EXPECT_EQ("2142433643", Sum("2142433642","1"));
}


TEST(Test2, Sum) {
	EXPECT_EQ("", Sum("2142433642", "-2142433642"));
}


TEST(Test3, Sum) {
	EXPECT_EQ("-4284867284", Sum("-2142433642", "-2142433642"));
}


TEST(Test4, Sum) {
	EXPECT_EQ("4284867284", Sum("2142433642", "2142433642"));
}


TEST(Test5, Sum) {
	EXPECT_EQ("4284867283", Sum("4284867284", "-1"));
}
TEST(Test6, Sum) {
	EXPECT_EQ("2142433642", Sum("-2142433642", "4284867284"));
}

// -2142433642 4284867284