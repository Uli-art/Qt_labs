// ������������ ������ � 5 ���������: �������� �.�.
/*
������� 1 ������� 10
��������� ��������� ���������� �������� ��������� �����������
������������� ������� (�������) X = x0, x2,�, xn �� �������:

i = 0,1, ..., n.
����������� ������� ������ � ����������. ����������� �������� �������
������� �� ����� .
������������� ���������� ������ �� ���������� �������: ��� �������������
�������� ��������� �� 0,5, � ��� ������������� �������� �� 0,1. ���������������
������ ����� ������� �� ����� . ������������ �������.
�������� ������: n = 13.
*/
#include <iostream>
#include <cmath>
#include "..\Libs\StaticLib\Header.h";
const double pi = 3.14159;

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

int main()
{
    int size = 0;
    std::cout << "Enter size of array: \n";
    size = getValue();
    double* arr = new double[size];
    FillArray(arr, size);
    ShowArray(arr, size);
    TransformArray(arr, size);
    std::cout << std::endl << std::endl;
    ShowArray(arr, size);
    DeleteArray(arr);
}
