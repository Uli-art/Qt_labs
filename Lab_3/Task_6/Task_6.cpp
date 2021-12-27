//������������ ������ 3, ��������� �������� �.�.
/*
������� 6
���������� ����������� ����� ������ ��������� f(x) = 0 ���
������� �� ������ ��������. ������ ����� ����� �� ���������� ���������:
���������� �������� �� ������ �� ����� ��������� � ��������� ����� � ����
�������� �������, ����������� �� ������. ��������, ��� ������� ���
�����������, ������� ������ ���������. ��������� ������ ��������� �
������������, �� ������� ������ ��������� ������� ������ �����, ��������� ���,
� ������� ����� ��������� ��������, ������ � ����� ������ ��������, �����
������ � ������� ���.
������� 11
sin(log(X)) + x * 1 / cot(x^2))
*/

#include <iostream>
#include <cmath>

int main()
{
    std::cout << "into how many parts to divide the search area of the root: ";
    int parts;
    std::cin >> parts;
    double upBound = 1.5, downBound = 0.5, temp,x;
    double step = (upBound - downBound) / parts;
    double min = abs(sin(log(downBound)) + downBound * 1/tan(pow(downBound,2)));
    x = downBound;
    for (double i = downBound; i <= upBound; i += step) {
        temp = abs(sin(log(i)) + i * 1 / tan(pow(i, 2)));
        if (temp < min) {
            min = temp;
            x = i;
        }
    }
    std::cout << "Root of the equation: " << x;
}

