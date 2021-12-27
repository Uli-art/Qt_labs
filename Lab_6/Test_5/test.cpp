#include "gtest/gtest.h"
#include "../Task_5/Task_5.cpp"


TEST(Test1, calcComd) {
    std::string str1 = "cup";
    std::string str2 = "russia";
    int modul = 1000;
    int lengthOfStr = 14;

  EXPECT_EQ(752, calcComd(str1,str2,lengthOfStr,modul));
}

TEST(Test2, calcComd) {

    std::string str1 = "russian";
    std::string str2 = "codecup";
    int modul = 123;
    int lengthOfStr = 7;

    EXPECT_EQ(0, calcComd(str1, str2, lengthOfStr, modul));
}

TEST(Test3, calcComd) {

    std::string str1 = "codec";
    std::string str2 = "decup";
    int modul = 15;
    int lengthOfStr = 7;

    EXPECT_EQ(1, calcComd(str1, str2, lengthOfStr, modul));
}