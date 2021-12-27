// Task_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Задание 8.
У вас есть строка s и фишка, которую вы можете поставить на любой символ
этой строки.
После того, как вы поставите фишку, вы можете подвинуть ее вправо
несколько (возможно, ноль) раз, то есть сделать следующее действие
несколько раз: если текущая позиция фишки обозначена как i, фишка
перемещается в позицию i+1. Конечно же, это действие невозможно, если
фишка находится в последней позиции строки.
После того, как вы закончите двигать фишку вправо, вы можете подвинуть ее
влево несколько (возможно, ноль) раз, то есть сделать следующее действие
несколько раз: если текущая позиция фишки обозначена как i, фишка
перемещается в позицию i?1. Конечно же, это действие невозможно, если
фишка находится в первой позиции строки.
Когда вы ставите фишку или перемещаете ее, вы выписываете символ, на
котором оказалась фишка. Например, если строка s — abcdef, вы ставите
фишку на 3-й символ, двигаете ее вправо 2 раза, а затем двигаете ее влево 3
раза, вы выпишете строку cdedcb.
Вам даны две строки s и t. Ваше задание — определить, можно ли так
выполнить описанные операции со строкой s, что в результате вы выпишете
строку t.
Входные данные
В первой строке задано одно целое число q (1?q?500) — количество наборов
входных данных.
Каждый набор входных данных состоит из двух строк. В первой строке
задана строка s (1?|s|?500), во второй строке — строка t (1?|t|?2?|s|?1). Обе
строки состоят из строчных букв латинского алфавита.
Гарантируется, что сумма |s| по всем наборам входных данных не
превосходит 500.
Выходные данные
Для каждого набора выходных данных выведите «YES», если можно
выписать строку t, проводя описанные в условии действия со строкой s, или
«NO» в противном случае.
Каждую букву можно выводить в любом регистре (YES, yes, Yes будут
распознаны как положительный ответ, NO, no и nO будут распознаны как
отрицательный ответ).
*/

#include <iostream>
#include <string>

int FindFirstEl(std::string str1, std::string str2) {
    for (int i = 0; i < str1.length(); ++i) {
        if (str2[0] == str1[i]) {
            return i;
        }
    }
    return -1;
}

bool GoRight(std::string str2, int start, std::string str1, int position) {
    if (start == str2.length() - 1) return false;
    if (str1[start + 1] == str2[position]) {

        return true;
    }
    return false;
}

bool GoLeft(std::string str2, int start, std::string str1, int position) {
    if (start == 0) return false;
    if (str1[start - 1] == str2[position]) {

        return true;
    }
    return false;
}

std::string getAnswer(std::string& newStr, int start, std::string& str1, std::string& str2, int& position) {
    if (start == -1) {
        return "No";

    }
    else {
        newStr.push_back(str2[0]);

        while (GoRight(str2, start, str1, position) && position < str2.length()) {
            newStr.push_back(str2[position]);
            ++position;
            ++start;
        }
        while (GoLeft(str2, start, str1, position) && position < str2.length()) {
            newStr.push_back(str2[position]);
            ++position;
            --start;
        }

        if (newStr.length() != str2.length()) {
            return "No";
        }
        else {
            return "Yes";
        }
    }
}

