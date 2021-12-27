#include "gtest/gtest.h"
#include "../Task_4/Task_4.cpp"

TEST(Test1, Replace) {
	std::string str = "Too swift for Theex, too quick for Gallow";
	Replace(str);
	std::string expStr = "Tu svift for Ziks, tu kvikk for Gallov";
  EXPECT_EQ(expStr, str);
}

TEST(Test2, Replace) {
	std::string str = "Too strong for young Prince Joseph to follow.";
	Replace(str);
	std::string expStr = "Tu strong for ung Prinse Josef to follov.";
	EXPECT_EQ(expStr, str);
}

TEST(Test3, DeleteRecurringEl) {
	std::string str = "Tu svift for Ziks, tu kvikk for Gallov";
	DeleteRecurringEl(str);
	std::string expStr = "Tu svift for Ziks, tu kvik for Galov";
	EXPECT_EQ(expStr, str);
}

TEST(Test4, DeleteRecurringEl) {
	std::string str = "Tu strong for ung Prinse Josef to follov.";
	DeleteRecurringEl(str);
	std::string expStr = "Tu strong for ung Prinse Josef to folov.";
	EXPECT_EQ(expStr, str);
}

TEST(Test5, DeleteRecurringEl) {
	std::string str = "zzzz";
	DeleteRecurringEl(str);
	std::string expStr = "z";
	EXPECT_EQ(expStr, str);
}