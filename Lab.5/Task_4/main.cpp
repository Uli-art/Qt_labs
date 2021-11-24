// ������������ ������ � 5 ���������: �������� �.�.
/*
������� 4
������� ��������� ������������ ������ ������������ �����. ����������,
����������� �� ����� ��� �������� � ������� ���������. ���� ����������� �����
��������, �� ���������� �� ������� � ����� ����������. ����������� �������� �����
������� � �������� ������� � ������� �� �����.
������������ �������.

*/

#include <iostream>
#include "Task_4.h"
int main()
{
    std::cout << "Enter sizes of arrays: ";
    int size1, size2;
    size1 = getValue();
    size2 = getValue();

    double** arr = new double* [size1];
    for (int i = 0; i < size1; ++i) {
        arr[i] = new double[size2];
    }

    FillArray(arr, size1, size2);
    std::cout << std::endl;
    ShowArray(arr, size1, size2);

    int countOfZeroEl = 0;
    FindZeroElements(arr, size1, size2, countOfZeroEl);
    TransformArray(arr, size1, size2);
    std::cout << std::endl;
    ShowArray(arr, size1, size2);
    DeleteArray(arr, size1);
}
