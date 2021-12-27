#include "gtest/gtest.h"
#include "../Task_1/Task_1.cpp"
TEST(Test1, IsItANumber) {
	char a = '1';
  EXPECT_EQ(true, IsItANumber(a));
}

TEST(Test2, IsItANumber) {
	char a = 'v';
	EXPECT_EQ(false, IsItANumber(a));

}

TEST(Test3, IsItANumber) {
	char a = ' ';
	EXPECT_EQ(false, IsItANumber(a));

}