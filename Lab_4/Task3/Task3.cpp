// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Задание 3. (Номер задания = номер по списку).
Данан целочисленная матрица N. Найт сумму наименьших элементов ее нечетных строк и наибольших эл ее четных строк
*/

#include <iostream>

int main()
{
    std::cout << "Enter size:\n";
    int size;
    std::cin >> size;
    int** matr = new int* [size];
    for (int i = 0; i < size; ++i) {
        matr[i] = new int[size];
    }
    int sumOfMin = 0;
    int sumOfMax = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cin >> matr[i][j];
        }
    }
    int min = 0;
    int max = matr[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i % 2 == 0) {
                if (matr[i][j] > max) {
                    max = matr[i][j];
                }

            }
            else {
                if (matr[i][j] < min) {
                    min = matr[i][j];
                }
              
            }
        }
        sumOfMax += max;
        sumOfMin += min;
        if (i != size - 1) {
            if (i % 2 == 0) {
               min = matr[i + 1][0];
               max = 0;
            }
            else {
                max = matr[i + 1][0];
                min = 0;
            }
        }
    }
    std::cout << "sumOfMax = " << sumOfMax << " " << "sumOfMin = " << sumOfMin;
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
