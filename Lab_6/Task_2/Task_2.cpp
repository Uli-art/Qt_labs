// Task_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Задание 2 Вариант 10
В тексте найти и вывести на экран все слова максимальной и минимальной
длины.
*/

#include <iostream>
#include <string>

int GetLenght(char* str) {
    int lenght = 0;
    int i = 0;
    while (str[i] != '\0') {
        lenght++; i++;
    }
    return lenght;
}

void FindMinMax(int& maxLen, int& minLen, int* lenghts, int& countOfWorlds, char* str) {
    for (int i = 0; i < GetLenght(str); ++i) {
        int lenght = 0;
        while (str[i] != ' ' && i < GetLenght(str)) {
            lenght++; i++;
        }
        lenghts[countOfWorlds] = lenght;
        ++countOfWorlds;
        if (lenght != 0) {
            if (lenght > maxLen) {
                maxLen = lenght;
            }
            if (lenght < minLen) {
                minLen = lenght;
            }
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
