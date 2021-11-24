#include "gtest/gtest.h"
#include "..\DinamicLibForTask2\DinLib.h"

TEST(CountEl, Test1) {
    int arr[3] = { -1,-2,-3 };
    int count = 0;
    EXPECT_EQ(3, CountEl(arr, 0, 3, count));
}
TEST(CountEl, Test2) {
    int arr[3] = { 1, 2, 3 };
    int count = 0;
    EXPECT_EQ(0, CountEl(arr, 0, 3, count));
}
TEST(CountEl, Test3) {
    int arr[3] = { 0,0,0 };
    int count = 0;
    EXPECT_EQ(0, CountEl(arr, 0, 3, count));
}
