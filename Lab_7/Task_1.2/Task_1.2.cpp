// Task_1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Задание 1. Необходимо разработать программу для перевода чисел из
одной системы счисления в другую. Выполнить два варианта решения
задачи: с помощью массивов.
10) из девятичной в семнадцатеричную;
*/

#include <iostream>
#include <cmath>

int FindEl(int str) {
    char correct[17] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G' };
    return correct[str];
}

std::string Reverse(std::string str) {
    std::string reverseStr;
    for (int i = 0; i < str.length(); ++i) {
        reverseStr += str[str.length() - 1 - i];
    }
    return reverseStr;
}

double TranslateToTenth(std::string numInNinth) {
    double number = 0;
    double base = 1;
    bool fractional = false;
    int index = 0;
    std::string wholeNum;
    std::string fractNum;
    for (int i = 0; i < numInNinth.length(); ++i) {
        if (numInNinth[i] == '.') {
            fractional = true;
            index = i;
            break;
        }
        wholeNum += numInNinth[i];
    }
    for (int i = index + 1; i < numInNinth.length(); ++i) {
        fractNum += numInNinth[i];
    }
    numInNinth = Reverse(wholeNum);
    for (int i = 0; i < numInNinth.length(); ++i) {
        number += (numInNinth[i] - 48) * base;
        base *= 9;
    }
    if (fractional) {
        double newbase = 1.0 / 9;
        base = newbase;
        for (int i = 0; i < fractNum.length(); ++i) {
            number += (fractNum[i] - 48) * base;
            base *= newbase;
        }
    }
    return number;
}

std::string TranslateToSevenTeenth(std::string numInNinth) {
    bool negative = false;
    if (numInNinth[0] == '-') {
        negative = true;
        numInNinth[0] = '0';
    }
    double num = TranslateToTenth(numInNinth);
    std::string result;
    int base = 17;
    double fractional;
    int wholePart;
    fractional = modf(num, &num);
    wholePart = (int)num;
    if (wholePart == 0) {
        result += '0';
    }
    while (wholePart > 0){
        int temp;
        temp = wholePart % base;
        result += FindEl(temp);
        wholePart /= 17;
    }
    if (negative) {
        result += '-';
    }
    result = Reverse(result);
    if (fractional) {
        result += '.';
        double whole = 1;
        while (whole != 0) {
            fractional *= base;
            fractional = modf(fractional, &whole);
            result += FindEl(whole);
        }
    }
    return result;
}


