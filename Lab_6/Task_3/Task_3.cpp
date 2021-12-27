// Task_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
������� 3 ������� 10
������ ������ �����. � ������� ��� ������ ������
���������, �������� ��� ����������� (������������ � ��������� ��
��������) ��� ���. ��������, ������������ �������� �������:
���������� ����� �� ���� � �� ���� ����� �� ���� ������.
��������� ������� �� �����. ����������� ������� ������ ��
�������� �� ������������.
*/

#include <iostream>
#include <string>
int GetLenght(std::string str) {
    int lenght = 0;
    int i = 0;
    while (str[i] != '\0') {
        lenght++; i++;
    }
    return lenght;
}

void DeleteSpace(std::string& str, int& lenght) {
    for (int i = 0; i < lenght; ++i) {
        if(str[i] == ' '){
            --lenght;
            for (int j = i; j < lenght; ++j) {
                str[j] = str[j + 1];
            }
            
        }
    }
}

bool IsItPalindrom(std::string& str) {
    int lenght = GetLenght(str);
    DeleteSpace(str, lenght);
    for (int i = 0; i < lenght / 2; ++i) {
        if (str[i] != str[lenght - 1 - i])
            return false;
    }
    return true;
}
