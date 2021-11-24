#include "gtest/gtest.h"
#include "..\Task_5\Task_5.cpp"

TEST(FindEl, Test1) {
  
    bool x = true;
    int** arr = new int* [5]{
        new int[3] {3,5,6},
        new int[3] {9,5,3},
        new int[3] {36,7,2},
        new int[3] {3,5,6},
        new int[3] {7,4,2},
    };
    int* expected = new int[5]{ 3, 9, 3, 7, 3 };
    int count = 0;
    int* obtained = FindEl(arr, 5, 3, count);
    for (int i = 0; i < 5; i++) {
        if (expected[i] != obtained[i]) x = false;
    }
   /*for (int i = 0; i < 5; i++) {
        delete[] arr;
    }*/
    EXPECT_EQ(true, x);
}

TEST(FindEl, Test2) {

    bool x = true;
    int** arr = new int* [3]{
        new int[2] {2,5},
        new int[2] {4,5},
        new int[2] {36,7}
    };
    int* expected = new int[0]{};
    int count = 0;
    int* obtained = FindEl(arr, 3, 2, count);
    for (int i = 0; i < 0; i++) {
        if (expected[i] != obtained[i]) x = false;
    }
    /*for (int i = 0; i < 5; i++) {
         delete[] arr;
     }*/
    EXPECT_EQ(true, x);
}