//Лабораторная работа 3, выполнила Сидорова У.Ю.
/*
Задание 4
4. Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:
4.1 С использованием цикла;
4.2 Без использования цикла.
*/

#include <iostream>

int main()
{
    std::cout << "Enter number: ";
    int x;
    double sum = 0;
    std::cin >> x;
    if (x <= 1) {
        std::cout << 0;
        return 0;
    }
    int i = 2;
    for (; i <= x; i += 2) {
        sum += i;
    }
    std::cout << sum << std::endl;

    double s;
    int n;
    n = x / 2;
    s = n * (4 + (n - 1) * 2)/2;
    std::cout << s;
}

