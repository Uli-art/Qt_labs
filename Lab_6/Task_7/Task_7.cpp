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

bool IsItPalindrom(std::string& str) {
    int lenght = str.length();
    for (int i = 0; i < lenght / 2; ++i) {
        if (str[i] != str[lenght - 1 - i])
            return false;
    }
    return true;
}

bool ItHaveOneLetter(std::string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[0] != str[i])
            return false;
    }
    return true;
}


