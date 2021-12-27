//Лабораторная работа 3, выполнила Сидорова У.Ю.
/*
Задание 3
Состовить программу вычисления значений функции y = sin(x) - cos(x) на отрезке [А,Б] в точках
*/

#include <iostream>
#include <cmath> 
int main()
{
    const double pi = 3.14159265359;
    double y, x;
    double b = pi / 2;
    for (int i = 0; i < 21; i++) {
        x = i * b / 20;
        y = sin(x) - cos(x);
        std::cout << "y = " << y << " when x = " << x << std::endl;
    }
}

