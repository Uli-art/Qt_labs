// ������������ ������ �4 ���������: �������� �.�.
/*
������� 1
������� ���������� ����������� ������ �� k �����. ��������� � ������������ � ������� �������� �������������� ������� � ������� �� ����� �������� ������ � ���������� ���������
������� 10
����������, ����������� �� ������, �.�. �������� �� �� ��������� ����� ������� � ������ ������
*/

#include <iostream>

int main()
{
    const int size = 6;
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " " ;
    }
    std::cout << std::endl;
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            std::cout << "Array isn't symmetric";
            return 0;
        }
    }
    std::cout << "Array is symmetric";
}


