//������������ ������ 3, ��������� �������� �.�.
/*
������� 2
����� ����� ���� � ��������� 10^-3, ����� ���� �������� (1/2)^n + (1/3)^n
*/

#include <iostream>
#include <cmath>

int main()
{
	double e = 0.0000001;
	double sum = 0, d;
	int i = 1;
	do {
		d = pow(1.0 / 2.0, i) + pow(1.0 / 3.0 , i);
		sum += d;
		i++;
	} 
	while (d > e);
	std::cout << "Sum = " << sum ;
}

