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
int getValue()
{
    while (true)
    {
        int a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return a;
        }
    }
}
void DeleteArrays(int **arr,int size,int* newArray) {
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] newArray;
}

void FillArray(int** arr, const int size1, const int size2) {
    std::cout << "Enter elements of array:\n";
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            std::cin >> arr[i][j];
        }
    }
}

void ShowArray(int** const arr, const int size1, const int size2) {
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void ShowArray(int* const arr, const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

int Min(int size1, int size2) {
    int min = size1;
    if (size1 > size2)
        min = size2;
    return min;
}

void Array(int** const arr, int* newArray ,int size, int& realSize) {
    realSize = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i][i] % 2 == 0) {
            newArray[realSize] = arr[i][i];
            ++realSize;
        }
    }
}

int MultEl(int* arr, int realSize) {
    if (realSize == 0) {
        return 0;
    }
    int mult = 1;
    for (int i = 0; i < realSize; ++i) {
        mult *= arr[i];
    }
    return mult;
}
