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
#include "Task_7.h"

int main()
{
    std::cout << "Enter string: ";
    std::string str;
    std::getline(std::cin, str);
    if (ItHaveOneLetter(str)) {
        std::cout << -1;
    }
    else
    {
        if (!IsItPalindrom(str)) {
            std::cout << str.length();
        }
        else {
            std::cout << str.length() - 1;
        }
    }
}
