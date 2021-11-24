// Лабораторная работа № 5 Выполнила: Сидорова У.Ю.
/*
Задание 4
Создать двумерный динамический массив вещественных чисел. Определить,
встречаются ли среди них элементы с нулевым значением. Если встречаются такие
элементы, то определить их индексы и общее количество. Переставить элементы этого
массива в обратном порядке и вывести на экран.
Использовать функции.

*/

#include <iostream>
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
void FillArray(double** arr, const int size1, const int size2) {
    std::cout << "Enter elements of array: ";
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            std::cin >> arr[i][j];
        }
    }
}

void ShowArray(double** const arr, const int size1, const int size2) {
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DeleteArray(double** arr, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void FindZeroElements(double** arr, int size1, int size2, int &countOfZeroEl) {
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (arr[i][j] == 0) {
                std::cout << arr[i][j] << "(indexes: " << i << " " << j << ")" << " ";
                ++countOfZeroEl;
            }
        }
    }
    std::cout << std::endl << "Count of zero elements: " << countOfZeroEl;
}

void TransformArray(double** arr, int size1, int size2) {
    for (int i = 0; i < size1/2; ++i) {
        for (int j = 0; j < size2; ++j) {
            std::swap(arr[i][j],arr[size1 - 1-  i][size2 - 1 - j]);
        }
    }
    if (size1 % 2 == 1) {
        for (int j = 0; j < size2 / 2; ++j) {
            std::swap(arr[size1/2][j],arr[size1 / 2][size2 - j -1]);
        }
    }
}


