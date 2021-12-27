#include "gtest/gtest.h"
#include "../Task_6/Task_6.cpp"


TEST(Test1, CountOfAnagrams) {
	std::string str = "soln";
	EXPECT_EQ(24, CountOfAnagrams(str));
}

TEST(Test2, CountOfAnagrams) {
	std::string str = "asdfghjklzxcvb";
  EXPECT_EQ(87178291200, CountOfAnagrams(str));
}



TEST(Test3, CountOfAnagramsSek) {
	std::string str = "solo";
	int* arr = new int[1];
	arr[0] = 2;
	int elOfArr = 1;
	EXPECT_EQ(12, CountOfAnagramsSek(str, arr, elOfArr));
}
