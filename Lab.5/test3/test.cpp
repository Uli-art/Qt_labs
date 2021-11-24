#include "gtest/gtest.h"
#include "../Task_3/Task_3.cpp"

TEST(Min, Test1) {
  EXPECT_EQ(2, Min(2,3));
}

TEST(Min, Test2) {
    EXPECT_EQ(7, Min(7,9));
}

TEST(Min, Test3) {
    EXPECT_EQ(1, Min(1,1));
}

TEST(MultEl, Test4) {
    int arr[4] = {2,4,6,8};
    EXPECT_EQ(384, MultEl(arr, 4));
}

TEST(MultEl, Test5) {
    int arr[5] = { 0,2,4,6,8 };
    EXPECT_EQ(0, MultEl(arr, 5));
}