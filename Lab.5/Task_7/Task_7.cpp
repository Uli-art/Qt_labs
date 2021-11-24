// ������������ ������ � 5 ���������: �������� �.�.
/*
������� 7
����������� ������� ������ ��������� �������:
��������� �������� , ��� m = 10t
������� ������
������ ������ �������� ��� ����� �����: k (0 < k < 1019), n (0 < n < 1019) � t (0 < t < 10).
��������� ������ �������� ��� ���� � �� ��������������.
�������� ������
��� ������� ����� � ��������� ������ ������� ����� ����� � �������� x. ������ ������
�������� � �������.
������� ������
1234 1234 4
2323 99999999999 8
4 99999 9
888 888 8
0 0 0
�������� ������
Case #1: 736
Case #2: 39087387
Case #3: 494777344
Case #4: 91255296

*/

#include <iostream>
#include <windows.h> 
#include "cmath"
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
unsigned long long int Funk(unsigned long long int k, unsigned long long int n, unsigned long long int m) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        return (k * Funk((k * k) % m, n / 2, m) % m);
    }
    else {
        return Funk((k * k) % m, n / 2, m);
    }

}

