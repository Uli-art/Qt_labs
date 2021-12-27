//������������ ������ 3, ��������� �������� �.�.
/*
������� 5
���������� ��������� ������� Y(x) �� ������ �������� � ���
S(x), ����� � ������� ����������� ���� ����� �������� ������� � �������� ���
�� ���������, ����������� � ������� ����������� �������. ���������
������ ��������� � ������������ ���������� ������ ���� (n), ����� ��������� �
������������ ���������� �����, �� ������� �� ����� ��������� �������, �����
������������ ������ �� ������ ����� (x �� 0.1, �� 1), ��������� ������� ��������
������� � ������� ���� � � ������� ����������� ������� � ������� ���
��������. ������������� <cmath> ���������.
������� 11
(1 - x * x / 2) * cos(x) - x / 2 * sin(x)
*/

#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter number of members: \n";
    int n;
    std::cin >> n;
    std::cout << "Enter the number of numbers from which to count the function: \n";
    int num;
    std::cin >> num;
    if (n <= 0 || num <= 0) {
        return 0;
    }
    for (int i = 0; i < num; i++) {
        std::cout << "Enter number from which to count the function (0.1 <= x <= 1): \n";
        double x;
        std::cin >> x;
        if (0.1 > x || x > 1) {
            std::cout << "The number must be in between 0.1 <= x <= 1";
            continue;
        }
        double sum = 1;
        double denominator = 1;
        double x2 = x * x;
        double temp = 1;
        double tempx = 1;
        for (int j = 1; j < n; j++) {
            denominator *= 2 * j * (2 * j - 1);
            tempx *= x2;
            temp = double(2 * j * j + 1) / denominator * tempx;
            if (j % 2 != 0) {
                sum -= temp;
            }
            else {
                sum += temp;
            }
        }
        double y = (1 - x * x / 2) * cos(x) - x / 2 * sin(x);
        std::cout << "Series expansion: " << sum << " Standard function: " << y << std::endl;
    }

}

