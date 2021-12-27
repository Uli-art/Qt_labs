#include "gtest/gtest.h"
#include "../Task_9/Task_9.cpp"

TEST(Test1, convertIntoNewSystem) {
  EXPECT_EQ("21", convertIntoNewSystem(7));
}

TEST(Test2, convertIntoNewSystem) {
	EXPECT_EQ("211", convertIntoNewSystem(22));
}

TEST(Test3, convertIntoNewSystem) {
	EXPECT_EQ("133", convertIntoNewSystem(21));
}

TEST(Test4, convertIntoNewSystem) {
	EXPECT_EQ("12111321323212332311", convertIntoNewSystem(2142433642));
}
