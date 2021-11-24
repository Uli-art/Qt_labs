#include <iostream>
#include <cmath>
const double pi = 3.14159;
void FillArray(double* const arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = exp(-0.5 * i - 2 * pi) - atan(i + 0.1);
    }
}

void ShowArray(const double* const arr, const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

void TransformArray(double* const arr, const int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0)
            arr[i] += 0.5;
        else if (arr[i] > 0)
            arr[i] = 0.1;
    }
}

void DeleteArray(double* arr) {
    delete[] arr;
}
