// Лабораторная работа № 5 Выполнила: Сидорова У.Ю.
/*
Задание 1 Вариант 10
Составить программу вычисления значений элементов одномерного
динамического массива (вектора) X = x0, x2,…, xn по формуле:

i = 0,1, ..., n.
Размерность массива ввести с клавиатуры. Вычисленные элементы массива
вывести на экран .
Преобразовать полученный массив по следующему правилу: все отрицательные
элементы увеличить на 0,5, а все положительные заменить на 0,1. Преобразованный
массив также вывести на экран . Использовать функции.
Исходные данные: n = 13.
*/
#include <iostream>
#include <cmath>
#include "..\Libs\StaticLib\Header.h";
const double pi = 3.14159;

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

int main()
{
    int size = 0;
    std::cout << "Enter size of array: \n";
    size = getValue();
    double* arr = new double[size];
    FillArray(arr, size);
    ShowArray(arr, size);
    TransformArray(arr, size);
    std::cout << std::endl << std::endl;
    ShowArray(arr, size);
    DeleteArray(arr);
}
