// Task_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Задание 9. Сумма чисел в строке
В заданной строке, состоящей из букв, цифр и прочих символов, найдите
сумму всех чисел
*/

#include <iostream>
#include <string>

bool IsItANumber(char a) {
    char arr[10] = { '0', '1','2', '3', '4', '5', '6', '7', '8', '9' };
    for (int i = 0; i < 10; i++) {
        if (a == arr[i]) return 1;
    }
    return 0;
}

unsigned long long int CalcSum(std::string& str, std::string& newStr) {
    unsigned long long int sum = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (IsItANumber(str[i])) {
            newStr.push_back(str[i]);
        }
        else if (newStr != "") {
            unsigned long long int temp = atoi(newStr.c_str());
            sum += temp;
            temp = 0;
            newStr.clear();
        }
    }
    if (newStr != "") {
        unsigned long long int temp = atoi(newStr.c_str());
        sum += temp;
        newStr.clear();
    }
    return sum;
}
