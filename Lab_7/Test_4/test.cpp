#include "gtest/gtest.h"
#include "../Task_4/Task_4.cpp"

TEST(Test1, Output) {
  EXPECT_EQ("A78DEE6C", Output("53CF7736", "53CF7736", '+'));
}

TEST(Test2, Output) {
	EXPECT_EQ("-053CF7736", Output("53CF7736", "-A78DEE6C", '+'));
}

TEST(Test3, Output) {
	EXPECT_EQ("-0A78DEE6C", Output("-53CF7736", "-53CF7736", '+'));
}

TEST(Test4, Output) {
	EXPECT_EQ("53CF7736", Output("-53CF7736", "A78DEE6C", '+'));
}

TEST(Test5, Output) {
	EXPECT_EQ("00000000", Output("53CF7736", "53CF7736", '-'));
}

TEST(Test6, Output) {
	EXPECT_EQ("0FB4C54A1", Output("53CF7736", "-A78DEE6C", '-'));
}

TEST(Test7, Output) {
	EXPECT_EQ("053CF7736", Output("-53CF7736", "-A78DEE6C", '-'));
}

TEST(Test8, Output) {
	EXPECT_EQ("-0FB4C54A1", Output("-53CF7736", "A78DEE6C", '-'));
}