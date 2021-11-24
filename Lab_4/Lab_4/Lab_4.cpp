// Лабораторная работа №4 Выполнила: Сидорова У.Ю.
/*
Задание 1
Вывести одномерный статический массив из k чисел. Выполнить в соответствии с номером варианта индивидуальное задание и вывести на экран исходные данные и полученный результат
Вариант 10
Определить, симметричен ли массив, т.е. читается ли он одинаково слева направо и справа налево
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


