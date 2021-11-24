// Task_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
int main()
{
    std::cout << "Enter size:\n";
    int size;
    std::cin >> size;
    int* arr = new int [size];
    
    std::cout << "Enter matrix:";
    for (int i = 0; i < size; ++i) {
            std::cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];
    int indexMin = 0, indexMax = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) { 
            max = arr[i];
            indexMax = i; }
        if (arr[i] < min) {
            min = arr[i];
            indexMin = i;
        }
    }
    int start = std::min(indexMax, indexMin);
    int end = std::max(indexMax, indexMin);
    int count = 0;
    for (int i = start + 1; i < end; ++i) {
        arr[i] = 0;
        ++count;
    }
    if (count > size / 2) {
        int* newArr = new int[size - count];
        int j = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] != 0) {
                newArr[j] = arr[i];
                std::cout << newArr[j] << " ";
                ++j;
            }
            
        }
    }
    else {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
    }
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
