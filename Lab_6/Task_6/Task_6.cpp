// Task_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
bool ThereDuplicateLetters(std::string str) {
    for (int i = 0; i < str.length(); ++i) {
        for (int j = i + 1; j < str.length(); ++j) {
            if (str[i] == str[j]) {
                return true;
            }
        }
    }
    return false;
}

int* CountOfDupicateLetters(std::string str, int& elOfArray) {
    int* arrOfCounts = new int[str.length() / 2];
    int count;
    bool IsItDuplicateLetters;
    for (int i = 0; i < str.length(); ++i) {
        count = 1;
        IsItDuplicateLetters = false;
        for (int j = i + 1; j < str.length(); ++j) {
            if (str[i] == str[j] && str[i] != '\0' && str[j] !='\0') {
                IsItDuplicateLetters = true;
                count++;
                for (int k = j; k < str.length(); ++k) {
                    str[k] = str[k + 1];
                }
            }
        }
        if (IsItDuplicateLetters) {
            arrOfCounts[elOfArray] = count;
            ++elOfArray;
        }
    }
    return arrOfCounts;
}
unsigned long long int Factorial(int i)
{
    if (i == 0) return 1;
    else return i * Factorial(i - 1);
}

unsigned long long int CountOfAnagrams(std::string str) {
    return Factorial(str.length());
}

unsigned long long int CountOfAnagramsSek(std::string str, int* arrOfCounts, int& ElOfArray) {
    int fact = 1;
    for (int i = 0; i < ElOfArray; ++i) {
        fact *= Factorial(arrOfCounts[i]);
    }
    return Factorial(str.length()) / fact;
}

