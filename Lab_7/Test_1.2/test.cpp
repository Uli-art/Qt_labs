#include "gtest/gtest.h"
#include"../Task_1.2/Task_1.2.cpp"

TEST(Test1, TranslateToSevenTeenth) {
	EXPECT_EQ("20E5BE17", TranslateToSevenTeenth("2147483647"));
}

TEST(Test2, TranslateToSevenTeenth) {
	EXPECT_EQ("-20E5BE17", TranslateToSevenTeenth("-2147483647"));
}

TEST(Test3, TranslateToSevenTeenth) {
	EXPECT_EQ("20E5BE17.41C0", TranslateToSevenTeenth("2147483647.2147483647"));
}

TEST(Test4, TranslateToSevenTeenth) {
	EXPECT_EQ("1", TranslateToSevenTeenth("1"));
}

TEST(Test5, TranslateToSevenTeenth) {
	EXPECT_EQ("417EG9EC", TranslateToSevenTeenth("4284867284"));
}