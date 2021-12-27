// Task_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Задание 2 Вариант 10
В тексте найти и вывести на экран все слова максимальной и минимальной
длины.
*/

#include <iostream>
#include <string>
#include "Task_2.h";


int main()
{
    int size;
    std::cout << "Enter size: ";
    std::cin >> size;
    char* str = new char[size];
    std::cin.ignore();
    std::cin.getline(str, size, '\n');
    int minLen = size;
    int maxLen = -1;
    int* lenghts = new int[size / 2];
    int countOfWorlds = 0;

    FindMinMax(maxLen, minLen, lenghts, countOfWorlds, str);

    int sum = 0;
   
    for (int i = 0; i < countOfWorlds; ++i) {
        if (lenghts[i] == minLen || lenghts[i] == maxLen) {
            sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += lenghts[j] + 1;
            }
            for (int j = 0; j < lenghts[i]; ++j) {
                std::cout << str[sum + j];
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
