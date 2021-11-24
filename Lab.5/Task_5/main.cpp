// Лабораторная работа № 5 Выполнила: Сидорова У.Ю.
/*
Задание 5
Дан двумерный динамический массив целых чисел. Значения элементов данного
массива ввести с клавиатуры. Создать динамический массив из элементов,
расположенных в четных столбцах данного массива и имеющих нечетное значение.
Вычислить среднее арифметическое элементов динамического массива.
Вывести результат на экран.
Использовать функции.
*/

#include <iostream> 
#include "Task_5.h"

int main()
{
    std::cout << "Enter sizes of arrays: ";
    int size1, size2;
    size1 = getValue();
    size2 = getValue();

    int** arr = new int* [size1];
    for (int i = 0; i < size1; ++i) {
        arr[i] = new int[size2];
    }

    FillArray(arr, size1, size2);
    std::cout << std::endl;
    ShowArray(arr, size1, size2);
    std::cout << std::endl;

    int sizeNewArray = size1 * size2 / 2;
    int* newArray = FindEl(arr, size1, size2, sizeNewArray);
    ShowArray(newArray, sizeNewArray);
    double average = Average(newArray, sizeNewArray);
    std::cout << std::endl;
    std::cout << "Average: " << average;
   // DeleteArray(arr, size1);
    delete[]newArray;

}


