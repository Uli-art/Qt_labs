//������������ ������ 3, ��������� �������� �.�.
/*
������� 7
����� ����������� �����, ���������� ��� ���������, ��� ���
����� ��� ���� ����� �������� ������ �����.
*/

#include <iostream>
#include <cmath>

int main()
{
    int fRang, sRang;
    for (int i = 10; i < 100; i++) {
        fRang = i / 10;
        sRang = i % 10;
        if (pow(fRang + sRang, 3) == pow(i, 2)) {
            std::cout << "Two-digit number, cube the sum of the digits of which is equal to its square: " << i;
            return 0;
        }
    }
}

