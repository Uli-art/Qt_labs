#include "gtest/gtest.h"
#include"../Task_1.1/Task_1.1.cpp"

TEST(Test1, TranslateToTenth) {
  EXPECT_EQ(841031062, TranslateToTenth(2147483647));
}

TEST(Test2, TranslateToTenth) {
	double num = TranslateToTenth(2147483647.2147483647);
	if (num < 841031062.2412 + 0.00001 || num > 841031062.2412 - 0.00001) {
		EXPECT_EQ(true, true);
	}
	else {
		EXPECT_EQ(true, false);
	}
}

TEST(Test3, TranslateToTenth) {
	EXPECT_EQ(1, TranslateToTenth(1));
}

TEST(Test4, TranslateToTenth) {
	EXPECT_EQ(0, TranslateToTenth(-2147483647));
}
