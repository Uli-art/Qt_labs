#include "gtest/gtest.h"
#include "../Task_6/Task_6.cpp"

TEST(Test1, FcountOfIntrNum) {
  EXPECT_EQ(0, FcountOfIntrNum(1));
}

TEST(Test2, FcountOfIntrNum) {
	EXPECT_EQ(1, FcountOfIntrNum(10));
}

TEST(Test3, FcountOfIntrNum) {
	EXPECT_EQ(1, FcountOfIntrNum(9));
}

TEST(Test4, FcountOfIntrNum) {
	EXPECT_EQ(3, FcountOfIntrNum(34));
}

TEST(Test5, FcountOfIntrNum) {
	EXPECT_EQ(214243364, FcountOfIntrNum(2142433642));
}