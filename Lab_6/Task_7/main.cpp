// Task_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Задание 7.
В заданной строке S найти максимальную по длине подстроку, которая
не является палиндромом.
Формат входных данных:
На вход задается строка S, состоящая из строчных букв латинского
алфавита (1 ? |S| ? 105 ).
Формат выходных данных:
Выведите одно целое число — длина максимального непалиндрома.
Если такой подстроки не существует, то выведите -1.
*/

#include <iostream>
#include <string>
#include "Task_7.h"

int main()
{
    std::cout << "Enter string: ";
    std::string str;
    std::getline(std::cin, str);
    if (ItHaveOneLetter(str)) {
        std::cout << -1;
    }
    else
    {
        if (!IsItPalindrom(str)) {
            std::cout << str.length();
        }
        else {
            std::cout << str.length() - 1;
        }
    }
}
