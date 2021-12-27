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
#include"Task_3.h"

int main()
{
    std::cout << "Enter count of string: ";
    int size;
    std::cin >> size;
    std::string* arrOfString = new std::string[size];
    std::cin.ignore();
    for (int i = 0; i < size; ++i) {
        std::getline(std::cin, arrOfString[i]);
    }
    for (int i = 0; i < size; ++i) {
        if (IsItPalindrom(arrOfString[i])) {
            std::cout << "String " << i << " is a palindrom\n";
        }
        else {
            std::cout << "String " << i << " is not a palindrom\n";
        }
    }
}

