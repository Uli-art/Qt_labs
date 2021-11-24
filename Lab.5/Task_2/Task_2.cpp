// Лабораторная работа № 5 Выполнила: Сидорова У.Ю.
/*
Задание 2 Вариант 10
Для заданного одномерного массива B из N элементов найти количество элементов
массива, для которых выполняется условие
((cos B)^2 > 0) ^ (B < 0)
Рекурсивную функцию применять каждый раз отдельно для первой трети массива и для остальной
части (2/3) массива. Рекурсивные вызовы заканчивать, когда останется только один
или два элемента.
*/

#include <iostream>
#include <cmath>
#include <Windows.h>

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
    HINSTANCE load;
    load = LoadLibrary(L"DinamicLibForTask2.dll");
    typedef int (*countEl) (int*, int, int, int&);
    countEl CountEl;
    CountEl = (countEl)GetProcAddress(load, "CountEl");

    std::cout << "Enter size of array\n";
    int size;
    size = getValue();
    int* arr = new int[size];
    std::cout << "Enter elements of array:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    int count = 0;    

    std::cout << CountEl(arr, 0, size,count);
    FreeLibrary(load);
}

