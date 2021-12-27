#include "gtest/gtest.h"
#include "../Task_8/Task_8.cpp"

TEST(Test1, getAnswer) {
	std::string str1 = "abcdef";
	std::string str2 = "cdedcb";
	std::string newStr = "";
	int start = FindFirstEl(str1, str2);
	int position = 1;
  EXPECT_EQ("Yes", getAnswer(newStr, start, str1, str2, position));
}

TEST(Test2, getAnswer) {
	std::string str1 = "aaa";
	std::string str2 = "aaaaa";
	std::string newStr = "";
	int start = FindFirstEl(str1, str2);
	int position = 1;
	EXPECT_EQ("Yes", getAnswer(newStr, start, str1, str2, position));

}

TEST(Test3, getAnswer) {
	std::string str1 = "aa";
	std::string str2 = "aaaaa";
	std::string newStr = "";
	int start = FindFirstEl(str1, str2);
	int position = 1;
	EXPECT_EQ("No", getAnswer(newStr, start, str1, str2, position));
}


TEST(Test4, getAnswer) {
	std::string str1 = "ab";
	std::string str2 = "b";
	std::string newStr = "";
	int start = FindFirstEl(str1, str2);
	int position = 1;
	EXPECT_EQ("Yes", getAnswer(newStr, start, str1, str2, position));

}