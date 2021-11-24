// Task_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int findMaxEl(int** arr, int i, int j) {
    int max = arr[i][j];
    for (int a = 0; a <= i; ++a) {
        for (int b = 0; b <= j; ++b) {
            if (arr[a][b] > max) max = arr[a][b];
        }
    }
    return max;
}

int main()
{
    std::cout << "Enter sizes:\n";
    int sizeCol, sizeRow;
    std::cin >> sizeRow >> sizeCol;
    int** matr = new int* [sizeRow];
    for (int i = 0; i < sizeRow; ++i) {
        matr[i] = new int[sizeCol];
    }

    int** newMatr = new int* [sizeRow];
    for (int i = 0; i < sizeRow; ++i) {
        newMatr[i] = new int[sizeCol];
    }
    std::cout << "Enter matrix:";
    for (int i = 0; i < sizeRow; ++i) {
        for (int j = 0; j < sizeCol; ++j) {
            std::cin >> matr[i][j];
        }
    }
    
    for (int i = 0; i < sizeRow; ++i) {
        for (int j = 0; j < sizeCol; ++j) {
            newMatr[i][j] = findMaxEl(matr, i, j);
        }
    }
    for (int i = 0; i < sizeRow; ++i) {
        for (int j = 0; j < sizeCol; ++j) {
            std::cout << newMatr[i][j] << " ";
        }
        std::cout << std::endl;
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
