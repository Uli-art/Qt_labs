// Лабораторная работа № 7 Выполнила: Сидорова У.Ю
/*
Задание 1 Вариант 10
Необходимо разработать программу для перевода чисел из
одной системы счисления в другую. Выполнить два варианта решения
задачи: без использования массивов
10) из девятичной в семнадцатеричную;
*/

#include <iostream>
#include <cmath>
#include <iomanip>

double getValue()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Enter a double value: ";
        double a;
        std::cin >> a;

        // Проверка на предыдущее извлечение
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // удаляем лишние значения

            return a;
        }
    }
}

char FindEl(int num) {
    if (num < 10) {
        return num + 48;
    }
    else {
        return num + 65 - 10;
    }
}

int Length(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        ++count;
    }
    return count;
}


double TranslateToTenth(double numInNinth) {
    int base = 1;
    double fractional;
    int wholePart;
    fractional = modf(numInNinth, &numInNinth);
    wholePart = (int)numInNinth;
    double numInTen = 0;
    int length = Length(wholePart);
    for (int i = 0; i < length; ++i) {
        numInTen += (wholePart % 10) * base;
        wholePart /= 10;
        base *= 9;
    }
    if (fractional) {
        double addbase = 1.0 / 9;
        double newBase = addbase;
        double tenthBase = 0.1;
        for (int i = 0; i < 15; ++i) {
            int temp = (fractional * pow(10, i + 1));
            numInTen += temp * newBase;
            fractional -= temp * tenthBase;
            wholePart /= 10;
            newBase *= addbase;
            tenthBase *= 0.1;
        }
    }
    return numInTen;
}

void WholePart(int wholePart) {
    int base = 17;
    int remainder = wholePart % base;
    

    if (wholePart != 0) {
        wholePart /= base;
        WholePart(wholePart);
        std::cout << FindEl(remainder);

    }
}

void TranslateToSevenTeenth(double numInNinth) {
    bool negative = false;
    if (numInNinth < 0) {
        negative = true;
        numInNinth = abs(numInNinth);
    }
    double numInTen = TranslateToTenth(numInNinth);
    std::cout << std::setprecision(15) << numInTen << std::endl;
    int base = 17;
    double fractional;
    int wholePart;
    fractional = modf(numInTen, &numInTen);
    wholePart = (int)numInTen;
    
    if (negative) {
        std::cout << '-';
    }
    WholePart(wholePart);
    fractional *= pow(10, 9);
    if (fractional != 0)
        std::cout << '.';
    while ((int)fractional > 0) {
        int addFraction = (int)fractional;
        int remainder = addFraction % base;
        std::cout << FindEl(remainder);
        fractional /= base;
    }
}

