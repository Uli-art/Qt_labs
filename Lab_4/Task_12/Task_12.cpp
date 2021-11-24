// Task_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void DeleteDublEl(int* arr, int &size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] == arr[i]) {
                for (int h = i; h < size - 1; ++h) {
                    arr[h] = arr[h + 1];
                }
                --size;
            }
        }
    }

}
int main()
{
    std::cout << "Enter size:\n";
    int size;
    std::cin >> size;
    int* arr = new int[size];

    std::cout << "Enter array:";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    DeleteDublEl(arr, size);
    std::cout << "New size: " << size << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
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
