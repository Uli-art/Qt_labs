// Task_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Задание 5
Во многих прикладных задачах, таких как поиск в сети или расшифровка
генома, требуется совершать некоторые действия со строками. Например,
часто требуется по некоторым данным о строке восстановить ее саму.
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом
искомой строки S, а другая — ее префиксом. Также известна длина искомой
строки L, а также то, что строка S состояла только из строчных букв
латинского алфавита.
Необходимо определить число строк, удовлетворяющих этим
ограничениям. Так как это число может быть достаточно большим, то
необходимо вывести его по модулю m.
Входные данные
Первая строка содержит одно целое число t (1 ? t ? 100) — количество
наборов входных данных, которые необходимо обработать.
Описание каждого из наборов входных данных содержит три строки. Первая
из них содержит два целых числа: L и m (1 ? L ? 109
, 1 ? m ? 104
). Вторая и
третья строки содержат соответственно строки S1 и S2. Они непусты, состоят
из строчных букв латинского алфавита, их длины не превышают 200
символов.
Выходные данные
Для каждого набора входных данных выведите в отдельной строке остаток
от деления числа строк, удовлетворяющих требованиям условия, на m.
*/

#include <iostream>
#include <string>
#include <cmath>

bool Gluing(std::string str1, std::string str2, std::string& newStr, int& pos) {
    for (int i = str1.length() - 1; i > 0; --i) {
        if (str2[0] == str1[i]) {
            pos = i;
            for (int j = 0; j < str1.length() - i; ++j) {
                if (str2[j] != str1[i + j])
                    return false;
            }
            return true;
        }

    }

    return false;
}

int calcComd(std::string str1, std::string str2, int lengthOfStr, int modul) {
    int comb = 0;
        if (str1.length() + str2.length() == lengthOfStr)
        {
            if (str1 != str2) {
                comb = 2;
            }
            else {
                comb = 1;
            }
        }
        else if (str1.length() + str2.length() < lengthOfStr) {
            comb = pow(26, lengthOfStr - (str1.length() + str2.length())) * 2;
            comb %= modul;
        }
        else {

            std::string newStr = str1 + str2;
            int pos = 0;
            if (Gluing(str1, str2, newStr, pos)) {
                if ((str2.length() + pos) == lengthOfStr) {
                    comb += 1;

                }
            }
            newStr = str2 + str1;
            pos = 0;
            if (Gluing(str2, str1, newStr, pos)) {

                if ((str1.length() + pos) == lengthOfStr) {
                    comb += 1;

                }
            }
        }
        return comb;
    }

    /*if (newStr[str1.length()] == str2[str1.length() - pos]) {
        newStr.erase(str1.length() - pos, 1);
        return true;
    }
    return false;*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
