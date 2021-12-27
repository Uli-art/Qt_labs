// Task_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Задание 4. Осуществить сложение и вычитание чисел в заданной системе
счисления. В другую систему счисления не переводить. В системах
счисления больших десятичной использовать буквы по аналогии с
шестнадцатеричной системой. Разработать функции для выполнения
операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел.
10) в семнадцатеричной;
*/

#include <iostream>

bool IsItCorrect(std::string a) {
    char correct[18] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G', '-'};
    bool cor = false;
    for (int i = 0; i < a.length(); ++i) {
        cor = false;
        for (int j = 0; j < 18; ++j) {
            if (a[i] == correct[j]) {
                cor = true;
            }
        }
        if (!cor)
            return false;
    }
    return true;
}

std::string InputValidation() {
    std::cout << "Enter number\n";
    std::string a;
    while (true) {
        std::cin >> a;
        if (!IsItCorrect(a)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Oops, that input is invalid. Please try again.\n";
        }
        else {
            std::cin.ignore(32767, '\n');
            return a;
        }
    }
}

std::string Reverse(std::string str) {

    std::string reverseStr;
    for (int i = 0; i < str.length(); ++i) {
        reverseStr += str[str.length() - 1 - i];
    }
    return reverseStr;
}
int FindEl(char str) {
    char correct[17] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G' };
    for (int i = 0; i < 17; ++i) {
        if (str == correct[i]) {
            return i;
        }
    }
}
std::string Sum(std::string str1, std::string str2) {
    const char correct[17] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G' };
    size_t min, max;
    bool minStr2 = false;
    if (str1.length() > str2.length()) {
        max = str1.length();
        min = str2.length();
        minStr2  = true;
    }
    else {
        min = str1.length();
        max = str2.length();
    }

    str1 = Reverse(str1);
    str2 = Reverse(str2);
    if (minStr2) {
        for (size_t i = min; i < max; ++i) {
            str2 += '0';
        }
    }
    else {
        for (size_t i = min; i < max; ++i) {
            str1 += '0';
        }
    }
    std::string sum;
    int add = 0;
    for (int i = 0; i < str1.length(); ++i) {
        int temp1 = FindEl(str1[i]);
        int temp2 = FindEl(str2[i]);
        int tempSum = temp1 + temp2;
        if (add) {
            tempSum += add;
            add = 0;
        }
        sum += correct[tempSum % 17];
        add = tempSum / 17;
    }
    if (add) {
        sum += correct[add];
    }
    return sum;
}

std::string Subtraction(std::string str1, std::string str2) {
    const char correct[17] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G' };
    size_t min, max;
    bool convert = false;
    if ((str1.length() > str2.length()) && str1[0] != '0') {
        max = str1.length();
        min = str2.length();
    }
    else if ((str1.length() < str2.length()) && str2[0] != '0') {
        min = str1.length();
        max = str2.length();
        std::string temp = str1;
        str1 = str2;
        str2 = temp;
        convert = true;
    }
    else
    {
        min = str1.length();
        max = str2.length();
        for (int i = 0; i < str1.length(); ++i) {
            if (str2[i] > str1[i]) {
                std::string temp = str1;
                str1 = str2;
                str2 = temp;
                //if(str1[0] == '0' && str2[0] == '0')
                if(str1[0] == '0' && str2[0] != '0') {
                    convert = true;
                }
                break;
            }
        }
    }

    str1 = Reverse(str1);
    str2 = Reverse(str2);
        for (size_t i = min; i < max; ++i) {
            str2 += '0';
        }
    
    std::string minys;
    int get = 0;
    for (int i = 0; i < str1.length(); ++i) {
        
        int temp1 = FindEl(str1[i]);
        int temp2 = FindEl(str2[i]);
        int tempSum = temp1 - temp2;
        if (get) {
            if (tempSum + 17 >= get) {
                tempSum -= get;
                get = 0;
            }
        }
        if (temp1 >= temp2)
            tempSum += 0;
        else {
            get = 1;
            tempSum += 17;
        }
        
        minys += correct[tempSum % 17];
    }
    if (convert) {
        minys += '-';
    }
    return Reverse(minys);
}

std::string Output(std::string str1, std::string str2, char sign) {
     
        if (str1[0] == '-' && str2[0] == '-') {
            str1[0] = '0';
            str2[0] = '0';
            if (sign == '+') {
                std::string str = Sum(str1, str2);
                str += '-';
                return Reverse(str);
            }
            else {
                return Subtraction(str1, str2);
            }
        }
        else if (str1[0] != '-' && str2[0] != '-') {
            if (sign == '+') {
                std::string str = Sum(str1, str2);
                return Reverse(str);
            }
            else {
                return Subtraction(str1, str2);
            }
        }
        else if (str1[0] != '-' && str2[0] == '-') {
            str2[0] = '0';
            if (sign == '+') {
                return Subtraction(str1, str2);
            }
            else {
                std::string str = Sum(str1, str2);
               //str += '-';
                return Reverse(str);
            }
        }
        else {
            str1[0] = '0';
            if (sign == '+') {
                return Subtraction(str1, str2);
            }
            else {
                std::string str = Sum(str1, str2);
                str += '-';
                return Reverse(str);
            }
        }
}


