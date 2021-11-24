// Лабораторная работа № 5 Выполнила: Сидорова У.Ю.
/*
Задание 7
Рекурсивная функция задана следующим образом:
Вычислить значение , где m = 10t
Входные данные
Каждая строка содержит три целых числа: k (0 < k < 1019), n (0 < n < 1019) и t (0 < t < 10).
Последняя строка содержит три нуля и не обрабатывается.
Выходные данные
Для каждого теста в отдельной строке вывести номер теста и значение x. Формат вывода
приведен в примере.
Входные данные
1234 1234 4
2323 99999999999 8
4 99999 9
888 888 8
0 0 0
Выходные данные
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

