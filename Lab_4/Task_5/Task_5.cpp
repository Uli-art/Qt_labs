// Task_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void zeroElArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = 0;
    }
}
double Avg(int array[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}
int main()
{
    std::cout << "Enter size:\n";
    int size;
    std::cin >> size;
    int** matr = new int* [size];
    for (int i = 0; i < size; ++i) {
        matr[i] = new int[size];
    }
    double** newMatr = new double* [size];
    for (int i = 0; i < size; ++i) {
        newMatr[i] = new double[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cin >> matr[i][j];
        }
    }
    bool up = true;
    bool down = true;
    bool left = true;
    bool right = true;
    int temp[8];
    int el = 0;
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
            zeroElArray(temp, 8);
            el = 0;
            if (up) {
                temp[el] = matr[i - 1][j];
                ++el;
            }
            if (down) {
                temp[el] = matr[i + 1][j];
                ++el;
            }
            if (right) {
                temp[el] = matr[i][j + 1];
                ++el;
            }
            if (left) {
                temp[el] = matr[i][j - 1];
                ++el;
            }
            if (up && left) {
                temp[el] = matr[i - 1][j - 1];
                ++el;
            }
            if (up && right) {
                temp[el] = matr[i - 1][j + 1];
                ++el;
            }
            if (down && left) {
                temp[el] = matr[i + 1][j - 1];
                ++el;
            }
            if (down && right) {
                temp[el] = matr[i + 1][j + 1];
                ++el;
            }
            newMatr[i][j] = Avg(temp, el);
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
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
