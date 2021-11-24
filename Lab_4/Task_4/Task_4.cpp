// Task_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Найти количество локальных минимумов
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
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cin >> matr[i][j];
        }
    }
    bool up = true;
    bool down = true;
    bool left = true;
    bool right = true;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            bool up = true;
            bool down = true;
            bool left = true;
            bool right = true;
            if (i == 0) up = false;
            if (j == 0) left = false;
            if (i == size - 1) down = false;
            if (j == size - 1) right = false;

            if (up) {
                if ((matr[i][j] >= matr[i - 1][j])) continue;
            }
            if (down) {
                if ((matr[i][j] >= matr[i + 1][j]) ) continue;
            }
            if (right) {
                if ( (matr[i][j] >= matr[i][j + 1]) ) continue;
            }
            if (left) {
                if ( (matr[i][j] >= matr[i][j - 1]) )
                    continue;
            }
            if (up && left) {
                if (matr[i][j] >= matr[i - 1][j - 1]) continue;
            }
            if (up && right) {
                if (matr[i][j] >= matr[i - 1][j + 1]) continue;
            }
            if (down && left) {
                if (matr[i][j] >= matr[i + 1][j - 1]) continue;
            }
            if (down && right) {
                if (matr[i][j] >= matr[i + 1][j + 1]) continue;
            }
            count++;
        }
    }
    std::cout << "Count: " << count;
}
/*
 || ( || (matr[i][j] >= matr[i - 1][j + 1])
 || () || (matr[i][j] >= matr[i + 1][j + 1])
 || () (matr[i][j] >= matr[i + 1][j + 1]) ||
 (matr[i][j] >= matr[i + 1][j - 1]) || || (matr[i][j] >= matr[i - 1][j - 1])

*/