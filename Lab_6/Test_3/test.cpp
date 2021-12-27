#include "gtest/gtest.h"
#include "../Task_3/Task_3.cpp"


TEST(Test1, IsItPalindrom) {
	std::string str = "   ";
	EXPECT_EQ(true, IsItPalindrom(str));
}
TEST(Test2, IsItPalindrom) {
	std::string str = "my other string";
	EXPECT_EQ(false, IsItPalindrom(str));
}

TEST(Test3, IsItPalindrom) {
	std::string str = "my otherr ehtoy m";
	EXPECT_EQ(true, IsItPalindrom(str));
}