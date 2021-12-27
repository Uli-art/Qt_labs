#include "gtest/gtest.h"
#include "../Task_5/Task_5.cpp"

TEST(Test1, Translate) {
  EXPECT_EQ("MMMCMXCIX", Translate(3999));
}

TEST(Test2, Translate) {
	EXPECT_EQ("MMM", Translate(3000));
}

TEST(Test3, Translate) {
	EXPECT_EQ("MCCXXXIV", Translate(1234));
}

TEST(Test4, Translate) {
	EXPECT_EQ("III", Translate(3));
}