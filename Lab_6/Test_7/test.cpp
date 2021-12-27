#include "gtest/gtest.h"
#include "../Task_7/Task_7.cpp"

TEST(Test1, ItHaveOneLetter) {
	std::string str = "aaa";
  EXPECT_EQ(true, ItHaveOneLetter(str));
}

TEST(Test2, ItHaveOneLetter) {
	std::string str = "aaam";
	EXPECT_EQ(false, ItHaveOneLetter(str));
}

TEST(Test3, IsItPalindrom) {
	std::string str = "zxcvcxz";
	EXPECT_EQ(true, IsItPalindrom(str));
}