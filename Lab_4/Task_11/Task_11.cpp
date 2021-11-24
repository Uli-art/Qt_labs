// Task_11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Enter natural n\n";
    int n;
    std::cin >> n;

    int*** matr = new int** [n];
    for (int i = 0; i < n; ++i) {
        matr[i] = new int* [n];
        for (int j = 0; j < n; ++j) {
            matr[i][j] = new int[n];
        }
    }

    std::cout << "Enter cube\n";
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> matr[k][i][j];
            }
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += matr[i][i][i];
        sum2 += matr[i][n - 1 - i][i];
        sum3 += matr[i][i][n - 1 - i];
        sum4 += matr[i][n - 1 - i][n - 1 - i];
    }

    std::cout << "sum1 = " << sum1 << " sum2 = " << sum2 << "sum3 = " << sum3 << "sum4 = " << sum4 << std::endl;
    if (sum1 > sum2 && sum1 > sum3 && sum1 > sum4) {
        std::cout << "The biggesr sum = " << sum1 << "(diagonal 1)";
    }
    else if (sum2 > sum3 && sum2 > sum4 && sum2 > sum1) {
        std::cout << "The biggesr sum = " << sum2 << "(diagonal 2)";
    }
    else if (sum3 > sum4 && sum3 > sum1 && sum3 > sum2) {
        std::cout << "The biggesr sum = " << sum3 << "(diagonal 3)";
    }
    else if (sum4 > sum1 && sum4 > sum2 && sum4 > sum3) {
        std::cout << "The biggesr sum = " << sum4 << "(diagonal 4)";
    }
    else {
        std::cout << "There are two or more equal diagonals";
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            delete[] matr[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        delete[] matr[k];
    }
    delete[] matr;
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
