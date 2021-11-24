#include "gtest/gtest.h"
#include "../Task_4/Task_4.cpp"

TEST(FindZeroElements, Test1) {
    int col, row;
    col = row = 4;
    double** arr = new double* [4];
    for (int i = 0; i < 4; ++i) {
        arr[i] = new double[4];
    }
    double arr2[4][4] = {
       {3,4,5,0},
       {0,0,7,8},
       {2,3,0,6},
       {0,3,5,2}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[i][j] = arr2[i][j];
        }
    }
   
    int count = 0;
    FindZeroElements(arr, 4, 4, count);
  EXPECT_EQ(5, count);
}
TEST(FindZeroElements, Test2) {
    int col, row;
    col = row = 4;
    double** arr = new double* [4];
    for (int i = 0; i < 4; ++i) {
        arr[i] = new double[4];
    }
    double arr2[4][4] = {
       {3,4,5,8},
       {9,0.01,7,8},
       {2,3,9.06,6},
       {90,3,5,2}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[i][j] = arr2[i][j];
        }
    }

    int count = 0;
    FindZeroElements(arr, 4, 4, count);
    EXPECT_EQ(0, count);
}