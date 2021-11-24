// ������������ ������ � 5 ���������: �������� �.�.
/*
������� 3
��� ��������� ������������ ������ ����� ����� � ������������ n x k .
����������� ������� (n = 5, k = 6) ������ � ����������. �������� ��������� �������
������ � ����������. ������� ������������ ������ �� ���������, ������������� ��
������� ��������� ������� � ������� ������ ��������. ��������� ������������
��������� ������������� �������.
��������� ������ � ��������� ������������ ������� �� �����.
������������ �������.
*/

#include <iostream>
#include "Task_3.h"

int main()
{

    std::cout << "Enter sizes of arrays: ";
    int size1, size2;
    size1 = getValue();
    size2 = getValue();

    int** arr = new int* [size1];
    for (int i = 0; i < size1; ++i) {
        arr[i] = new int[size2];
    }

    FillArray(arr, size1, size2);
    std::cout << std::endl;
    ShowArray(arr, size1, size2);
    int size = Min(size1, size2);

    int* newArray = new int[size];
    int realSize = 0;
    Array(arr, newArray, size, realSize);
    int result = MultEl(newArray, realSize);

    std::cout << std::endl;
    std::cout << "New array: ";
    ShowArray(newArray, realSize);
    std::cout << std::endl;
    std::cout << "Multiplication of elements: " << result;

    DeleteArrays(arr, size2, newArray);
}