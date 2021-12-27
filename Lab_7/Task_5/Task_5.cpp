// Лабораторная работа №7
/*
Задание 5. Перевести число из арабской системы записи чисел в римскую.
*/

#include <iostream>
#include <algorithm>
int Value()
{
    while (true) 
    {
        std::cout << "Enter a int value: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() || a <= 0)
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

int Length(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        ++count;
    }
    return count;
}

std::string Translate(int num) {
    int digit = pow(10, (Length(num) - 1));
    std::string result;
    while (num > 0) {
        int add;
        add = num / digit;
        add *= digit;
        if (add <= 9) {
            if (add == 9) {
                result += "IX";
            }
            else if (add == 4) {
                result += "IV";
            }
            else {
                if (add >= 5) {
                    result += 'V';
                }
                for (int i = 0; i < add % 5; ++i) {
                    result += 'I';
                }
                
                
            }
        }
        else if (add <= 90) {
            if (add == 10) {
                result += 'X';
            } else if (add == 90) {
                result += "XC";
            }
            else if (add == 40) {
                result += "XL";
            }
            else {
                if (add >= 50) {
                    result += 'L';
                }
                for (int i = 0; i < add / 10 % 5; ++i) {
                    result += 'X';
                }
               
            }
        }
        else if (add <= 900) {
            if (add == 100) {
                result += 'C';
            }
            else if (add == 900) {
                result += "CM";
            }
            else if (add == 400) {
                result += "CD";
            }
            else {
                if (add >= 500) {
                    result += 'D';
                }
                for (int i = 0; i < add / 100 % 5; ++i) {
                    result += 'C';
                }
               
            }
        }
        else if (add <= 3000) {
                for (int i = 0; i < add / 1000 % 5; ++i) {
                    result += 'M';
                }
               
        }
        num -= add;
        digit /= 10;
    }
    return result;
}


                      
// 3000 900 90 9    MMM CM XC IX 