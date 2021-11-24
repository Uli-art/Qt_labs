// testXor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int CountEl(int* arr, int sizeF, int sizeS, int& count) {
    for (sizeF = 0; sizeF < sizeS; sizeF++) {
        double x = cos(arr[sizeF]);
        if ((pow(x, 2) > 0) ^ (arr[sizeF] < 0)) {
            ++count;
        }
    }
    if (sizeF == sizeS) return count;
    CountEl(arr, sizeS / 3 + 1, sizeS, count);
}
int main()
{
    int arr[3] = { -1,-2,-3 };
    int count = 0;
    std::cout << CountEl(arr, 0, 3, count);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
