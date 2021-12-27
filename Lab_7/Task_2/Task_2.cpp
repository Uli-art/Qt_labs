// Task_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Задание 2 Вариант 10
Перевести числа. Предусмотреть ввод положительных и
отрицательных чисел.
10. Из прямого кода в дополнительный
*/

#include <iostream>
bool IsItCorrect(std::string a) {
    for (int i = 0; i < a.length(); ++i) {
        if (!(a[i] == '1' || a[i] == '0')) {
            return false;
        }
    }
    return true;
}

std::string InputValidation() {
    std::cout << "Enter number\n";
    std::string a;
    while (true) {
        std::cin >> a;
        if (!IsItCorrect(a)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid. Please try again.\n";
        }
        else {
            std::cin.ignore(32767, '\n');
            return a;
        }
    }
}

std::string ConverToReverseCode(std::string& str) {
    if (str[0] == '0') {
        return str;
    } 
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == '1') {
            str[i] = '0';
        }
        else {
            str[i] = '1';
        }
    }
    return str;
}

std::string ConverToAdditionalCode(std::string str) {
    std::string str1 = ConverToReverseCode(str);
    if (str[0] == '0') {
        return str1;
    }
    if (str1[str1.length() - 1] == '0') {
        str1[str1.length() - 1] = '1';
    }
    else {
        int i = 2;
        str1[str1.length() - 1] = '0';
        str1[str1.length() - i] = '2';
        while (str1[str1.length() - i] == '2' && i != str1.length()) {
            str1[str1.length() - i] = '0';
            if(str1[str1.length() - i - 1] == '1')
                str1[str1.length() - i - 1] = '2';
            i++;
        }
    }
    if (str1[0] == '2')
        str1[0] = '0';
    return str1;
}

