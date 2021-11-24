#include "gtest/gtest.h"
#include "..\Libs\StaticLib\Array.cpp"

TEST(TransformArray, Test1) {
    bool x = true;
    double arr[4];
    for (int i = 0; i < 4; i++) {
        arr[i] = exp(-0.5 * i - 2 * pi) - atan(i + 0.1);
    }
    TransformArray(arr, 4);
    double exeptionArr[4] = { 0.402199, -0.331849, -0.62569, -0.758338 };
    for (int i = 0; i < 4; i++) {
        if ((arr[i] < exeptionArr[i] - 0.000001) || (arr[i] > exeptionArr[i] + 0.000001)) x = false;
    }
    EXPECT_EQ(true, x);
}