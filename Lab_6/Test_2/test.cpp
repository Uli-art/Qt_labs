#include "gtest/gtest.h"
#include "../Task_2/Task_2.cpp"

TEST(Test1, GetLenght) {
	char* str = "my other string";
  EXPECT_EQ(15 , GetLenght(str));
}

TEST(Test2, GetLenght) {
	char* str = "";
	EXPECT_EQ(0, GetLenght(str));
}

TEST(Test3, FindMinMax) {
	int size = 20;
	int minLen = size;
	int maxLen = -1;
	int* lenghts = new int[size / 2];
	int countOfWorlds = 0;
	char* str = "my other string";
	FindMinMax( maxLen, minLen, lenghts, countOfWorlds,  str);
	EXPECT_EQ(2,minLen);
	EXPECT_EQ(6, maxLen);
}

TEST(Test4, FindMinMax) {
	int size = 20;
	int minLen = size;
	int maxLen = -1;
	int* lenghts = new int[size / 2];
	int countOfWorlds = 0;
	char* str = "my ot st";
	FindMinMax(maxLen, minLen, lenghts, countOfWorlds, str);
	EXPECT_EQ(2, minLen);
	EXPECT_EQ(2, maxLen);
}