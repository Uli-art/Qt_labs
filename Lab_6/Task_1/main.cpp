/*
Лабораторная работа №6 Выполнила: Сидорова У.Ю
Задание 1 Вариант 10
Рассматривать строки как одномерный массив символов.
При выполнении задания предусмотреть возможность ввода текста с
клавиатуры. При работе с текстом использовать строки длиной не более 80-
ти символов. Исходный текст и полученный результат вывести на экран.
Дана строка символов, состоящая из цифр, разделенных пробелами. Вывести
четные числа этой строки.
*/
#include <iostream>
#include <cstring>
#include "Task_1.h"

int main()
{
    char str[80] = "";
    // std::cin.getline(str, 80);
    std::cout << "Do you want to use random(1) or enter line by yourself?\n";
    int answer;
    std::cin >> answer;
    if (answer == 1) {
        char arr[10] = { '0', '1','2', '3', '4', '5', '6', '7', '8', '9' };
        for (int i = 0; i < 80; i += 2) {
            int a = rand() % 10;
            str[i] = arr[a];
            str[i + 1] = ' ';
            std::cout << str[i] << str[i + 1];
        }
    }
    else {
        //std::cin >> answer;
        //std::cin.getline(str, 80);
        std::cin.ignore();
        std::cin.getline(str, 80);
    }
    std::cout << '\n';
    for (int i = 0; i < strlen(str); i++) {

        char temp[80] = "";
        int j = 0;
        while (str[i] != ' ' && str[i] != '\0') {
            temp[j] = str[i];
            ++i; ++j;
        }
        if (strlen(temp) == 1) {
            if (IsItANumber(str[i - 1])) {
                if (str[i - 1] % 2 == 0)
                    std::cout << str[i - 1] << " ";
            }
        }
    }
    return 0;
}
