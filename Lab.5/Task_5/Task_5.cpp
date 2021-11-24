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
void FillArray(int** arr, const int size1, const int size2) {
    std::cout << "Enter elements of array: ";
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            std::cin >> arr[i][j];
        }
    }
}

void ShowArray(int** const arr, const int size1, const int size2) {
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void ShowArray( int* const arr,  int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

void DeleteArray(int** arr, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int* FindEl( int** const arr, int size1, int size2, int& sizeNewArray) {
    int* newArray = new int[sizeNewArray];
    sizeNewArray = 0;
    for (int j = 0; j < size2; j += 2) {
        for (int i = 0; i < size1; ++i) {
            if (arr[i][j] % 2 == 1) {
                newArray[sizeNewArray] = arr[i][j];
                ++sizeNewArray;
            }
        }
    }
    if (sizeNewArray == size1*size2/2) {
        return newArray;
    }

    int* optimisedArray = new int[sizeNewArray];
    for (int i = 0; i < sizeNewArray; i++) {
        optimisedArray[i] = newArray[i];
    }
    delete[]arr;
    return optimisedArray;
}

double Average(int * newArray, int sizeNewArray) {
    double sum = 0;
    if (sizeNewArray == 0) {
        return 0;
    }
    for (int i = 0; i < sizeNewArray; i++) {
        sum += newArray[i];
    }
    return sum / sizeNewArray;
}



