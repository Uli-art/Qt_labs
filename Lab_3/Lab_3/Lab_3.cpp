//������������ ������ 3, ��������� �������� �.�.
/*
������� 1
(������������ while) ��������� ����� 30 ��������� (� - �)^2


#include <iostream>
#include <cmath>

int main()
{
    int i = 1;
    int a, b, sum = 0, temp;
    while (i < 31) {
        if (i % 2 == 0) {
            a = i / 2;
            b = pow(i, 3);
        }
        else {
            a = i;
            b = pow(i,2);
        }
        temp = pow(a-b,2);
        sum += temp;
        i++;
    }
    std::cout << "Sum = " << sum;


}*/
#include <iostream>
int main()
{
    std::cout << -10 & 26;
    return 0;
}