#include "DinLib.h"
#include <cmath>

extern "C" __declspec(dllexport) int CountEl(int* arr, int sizeF, int sizeS, int& count) {
    for (sizeF = 0; sizeF < sizeS; sizeF++) {
        double x = cos(arr[sizeF]);
        bool tmp = (pow(x, 2) > 0) ^ (arr[sizeF] < 0);
        if (tmp) {
            ++count;
        }
    }
    if (sizeF == sizeS) return count;
    CountEl(arr, sizeS / 3 + 1, sizeS, count);
}