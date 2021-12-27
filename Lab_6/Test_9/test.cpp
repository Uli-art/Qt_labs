#include "gtest/gtest.h"
#include "../Task_9/Task_9.cpp"
TEST(Test1, CalcSum) {
	std::string str1 = "vfgs o45sa 5 ioe9";
	std::string newStr = "";
  EXPECT_EQ(59, CalcSum(str1, newStr));
}

TEST(Test2, CalcSum) {
	std::string str1 = "vfgs osa ioe";
	std::string newStr = "";
	EXPECT_EQ(0, CalcSum(str1, newStr));
}

TEST(Test3, CalcSum) {
	std::string str1 = "2147483647";
	std::string newStr = "";
	EXPECT_EQ(2147483647, CalcSum(str1, newStr));
}