// Task_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
������� 8.
� ��� ���� ������ s � �����, ������� �� ������ ��������� �� ����� ������
���� ������.
����� ����, ��� �� ��������� �����, �� ������ ��������� �� ������
��������� (��������, ����) ���, �� ���� ������� ��������� ��������
��������� ���: ���� ������� ������� ����� ���������� ��� i, �����
������������ � ������� i+1. ������� ��, ��� �������� ����������, ����
����� ��������� � ��������� ������� ������.
����� ����, ��� �� ��������� ������� ����� ������, �� ������ ��������� ��
����� ��������� (��������, ����) ���, �� ���� ������� ��������� ��������
��������� ���: ���� ������� ������� ����� ���������� ��� i, �����
������������ � ������� i?1. ������� ��, ��� �������� ����������, ����
����� ��������� � ������ ������� ������.
����� �� ������� ����� ��� ����������� ��, �� ����������� ������, ��
������� ��������� �����. ��������, ���� ������ s � abcdef, �� �������
����� �� 3-� ������, �������� �� ������ 2 ����, � ����� �������� �� ����� 3
����, �� �������� ������ cdedcb.
��� ���� ��� ������ s � t. ���� ������� � ����������, ����� �� ���
��������� ��������� �������� �� ������� s, ��� � ���������� �� ��������
������ t.
������� ������
� ������ ������ ������ ���� ����� ����� q (1?q?500) � ���������� �������
������� ������.
������ ����� ������� ������ ������� �� ���� �����. � ������ ������
������ ������ s (1?|s|?500), �� ������ ������ � ������ t (1?|t|?2?|s|?1). ���
������ ������� �� �������� ���� ���������� ��������.
�������������, ��� ����� |s| �� ���� ������� ������� ������ ��
����������� 500.
�������� ������
��� ������� ������ �������� ������ �������� �YES�, ���� �����
�������� ������ t, ������� ��������� � ������� �������� �� ������� s, ���
�NO� � ��������� ������.
������ ����� ����� �������� � ����� �������� (YES, yes, Yes �����
���������� ��� ������������� �����, NO, no � nO ����� ���������� ���
������������� �����).
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

