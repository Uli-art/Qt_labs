// Лабораторная работа № 5 Выполнила: Сидорова У.Ю.
/*
Задание 8
Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).
Входные данные
Каждая строка содержит одно натуральное число n (n ≤ 109).
Выходные данные
Для каждого значения n в отдельной строке вывести значение суммы f(1) + f(2) + ... + f(n).
Входные данные #1
7
1
777
Выходные данные #1
21
1
201537

*/

#include <iostream>
#include <cmath>
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
int GreatestOddDivisor(int n) {
    if (n > 0) {
        int k = n;
        while (k % 2 == 0) {
            k /= 2;
        }
        return k + GreatestOddDivisor(n - 1);
    }
    else return 0;
}



