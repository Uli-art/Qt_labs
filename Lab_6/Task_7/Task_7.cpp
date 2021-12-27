// Task_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
������� 7.
� �������� ������ S ����� ������������ �� ����� ���������, �������
�� �������� �����������.
������ ������� ������:
�� ���� �������� ������ S, ��������� �� �������� ���� ����������
�������� (1 ? |S| ? 105 ).
������ �������� ������:
�������� ���� ����� ����� � ����� ������������� ������������.
���� ����� ��������� �� ����������, �� �������� -1.
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


