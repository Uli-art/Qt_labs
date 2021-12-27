// Task_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Задание 3. Осуществить сложение чисел. Разработать функции для
выполнения операции сложения. Предусмотреть ввод положительных и
отрицательных чисел.
1. Найдите сумму двоичных чисел, заданных в естественной
форме. Сложение выполните в дополнительном коде. Ответ
выразите в естественной форме
*/
#include <iostream>
#include <string>
#include <cmath>


bool IsItCorrect(std::string a) {
    for (int i = 0; i < a.length(); ++i) {
        if (!(a[i] == '1' || a[i] == '0')) {
            return false;
        }
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

void CorrectForm(std::string& str1, std::string& str2, std::string numStr1, std::string numStr2) {
    size_t temp;
    if (str1.length() < str2.length()) {
        
        temp = str2.length() - str1.length();
        for (int i = 0; i < temp; ++i) {
            str1 += 48;
        }
    }
    else if (str1.length() > str2.length()) {
        temp = str1.length() - str2.length();
        for (int i = 0; i < temp; ++i) {
            str2 += 48;
        }
    }
    else {}
    if (numStr1[0] == '-') {
        str1 += 49;
    } else { str1 += 48; }
    if (numStr2[0] == '-') {
        str2 += 49;
    }
    else { str2 += 48; }
}

std::string DivitionBy2(std::string& str) {
    int divider = 2;
    int convert = 0;
    bool isIt10 = false;
    int countOfDigits = 0;
    std::string strAnwer;
    if (str[0] == '1' && str.length() == 1)
        return "0";
    for (int i = 0; i < str.length(); ++i) {
        convert = (int)str[i] - 48;
        if (convert < divider && isIt10 != true) {

            if(convert != 0)
            isIt10 = true;
            if (i != 0) {
                int result = 48;
                strAnwer += 48;
                ++countOfDigits;
            }
            continue;
        }
        else {
            int temp = convert;
            convert /= divider;
            
            if (isIt10) {
                convert += 5;
                isIt10 = false;
            }
            if (temp % divider == 1) {
                isIt10 = true;
            }
            
            convert += 48;
            strAnwer += convert;
            
        }
        ++countOfDigits;
    }
    return strAnwer;
}

std::string ConvertToBinaryCode(std::string str1) {
    std::string str;
    if (str1[0] == '-') {
        for (int i = 1; i < str1.length(); ++i)
            str += str1[i];
    }
    else {
        str = str1;
    }
    std::string bianarystr;
    int convert = 0;

    while(!(str == "0")) {
        convert = (int)str[str.length() - 1] - 48;
        if (convert % 2 == 0) {
            bianarystr += 48;
        }
        else {
            bianarystr += 49;
        }

        std::string temp = str;
        str = DivitionBy2(temp);
    }
    return bianarystr;
}

void ConvertToReverseCode(std::string& str) {
    if (str[str.length() - 1] == '0') {
        return;
    }
    for (int i = 0; i < str.length() - 1; ++i) {
        if (str[i] == '1') {
            str[i] = '0';
        }
        else {
            str[i] = '1';
        }
    }
}

std::string ConvertToAdditionalCode(std::string& str) {
    ConvertToReverseCode(str);
    if (str[str.length() - 1] == '0') {
        return str;
    }
    if (str[0] == '0') {
        str[0] = '1';
    }
    else {
        int i = 1;
        str[0] = '0';
        str[i] += 1;
        while (str[i] == '2' && i != str.length() - 2) {
            str[i] = '0';
            str[i + 1] += 1;
            i++;
        }
    }
    if (str[str.length() - 2] == '2') {
        str[str.length() - 2] = '0';
        str += '1';
    }
    return str;
}

std::string ConvertToTen(std::string str) {
    std::string sum = "";
    std::string number;
    for (int i = 0; i < str.length() - 1; ++i) {
        if (str[i] == '1') {
            unsigned long long int temp = pow(2, i);
            int j = 0;
            number = "";
            while (temp != 0) {
                number += temp % 10 + 48;
                temp /= 10;
                ++j;
            }
            size_t max, min;
            bool num = false;
            if (j > sum.length()) {
                min = sum.length();
                max = j;
                num = true;
            }
            else {
                max = sum.length();
                min = j;
            }
            if (num) {
                for (size_t i = min; i < max; ++i)
                    sum += 48;
            }
            else {
                for (size_t i = min; i < max; ++i)
                    number += 48;
            }
            for (int k = 0; k < max; ++k) {
                int tempNum = sum[k] + number[k] - 48 * 2;
                sum[k] = tempNum % 10 + 48;
                if (tempNum >= 10) {
                    if (k + 1 == sum.length())
                        sum += 48;
                    sum[k + 1] += tempNum / 10;
                }
            }
        }
    }
    if (str[str.length() - 1] == '1')
        sum += '-';
    std::string sum1;
    for (int i = 0; i < sum.length(); ++i) {
        sum1 += sum[sum.length() - 1 - i];
    }
    return sum1;
}

std::string ConvertAdditionalFormToReverce(std::string& str) {
    if (str[0] == '1')
        str[0] = '0';
    else {
        bool takeOne = false;
        int i = 0;
        while (str[i] != '1' && i < str.length() - 1) {
            str[i] = '1';
            ++i;
        }
        str[i] = '0';
    }
    return str;
}
// 1000
//    1
// 0111
/*574 -56
Additional code of str1: 01000111110
Additional code of str2: 11111001000
1653*/

std::string Reverse(std::string str) {

    std::string reverseStr;
    for (int i = 0; i < str.length(); ++i) {
        reverseStr += str[str.length() - 1 - i];
    }
    return reverseStr;
}

std::string Subtraction(std::string str1, std::string str2, std::string numStr1, std::string numStr2) {
    size_t min, max;
    bool convert = false;
   
    if (numStr1[0] == '-') {
        numStr1[0] = '0';
        numStr2 = '0' + numStr2;
    }
    if (numStr2[0] == '-') {
        numStr2[0] = '0';
        numStr1 = '0' + numStr1;
    }

    if ((numStr1.length() > numStr2.length())) {
        max = str1.length();
        min = str2.length();
        if (str1[str1.length() - 1] == '1')
            convert = true;
    }
    else if ((numStr1.length() < numStr2.length())) {
        min = str1.length();
        max = str2.length();
        std::string temp = str1;
        str1 = str2;
        str2 = temp;
        if (str2[str2.length() - 1] == '1')
            convert = true;
    }
    else
    {
        min = str1.length();
        max = str2.length();
       
        for (int i = 0; i < numStr1.length(); ++i) {
            if (numStr2[i] > numStr1[i]) {
                if (str2[str2.length() - 1] == '1')
                    convert = true;
                std::string temp = str1;
                str1 = str2;
                str2 = temp;
                
                break;
            }
        }
        if (!convert) {
            if (str1[str1.length() - 1] == '1')
                convert = true;
        }
    }

    if (str1[str1.length() - 1] == '1') {
        str1[str1.length() - 1] = '0';
    }
    if (str2[str2.length() - 1] == '1') {
        str2[str2.length() - 1] = '0';
    }
   // str1 = Reverse(str1);
    //str2 = Reverse(str2);
    for (size_t i = min; i < max; ++i) {
        str2 += '0';
    }
    std::string minys;
    int get = 0;
    for (int i = 0; i < str1.length(); ++i) {
        int temp = (str1[i] - str2[i]) + 48 - get;
        get = 0;
        if (temp < 48) {
            temp += 2;
            get = 1;
        }
        minys += temp;
    }
    if (convert) {
        minys += '1';
    }
    else {
        minys += '0';
    }
    //minys = Reverse(minys);
    return minys;
}

std::string Sum(std::string str1, std::string str2) {
    std::string numStr1 = str1;
    std::string numStr2 = str2;
    str1 = ConvertToBinaryCode(str1);
    str2 = ConvertToBinaryCode(str2);
    CorrectForm(str1, str2, numStr1, numStr2);
    if ((numStr1[0] == '-' && numStr2[0] != '-') || (numStr1[0] != '-' && numStr2[0] == '-')) {
        std::string substraction;
        substraction = Subtraction(str1, str2, numStr1, numStr2);
        //ConvertAdditionalFormToReverce(substraction);
        //ConvertToReverseCode(substraction);
        return ConvertToTen(substraction);
    }
    str1 = ConvertToAdditionalCode(str1);
    std::cout << "Additional code of str1: ";
    for (int i = 0; i < str1.length(); ++i) {
        std::cout << str1[str1.length() - 1 - i];
    }
    std::cout << std::endl;
    str2 = ConvertToAdditionalCode(str2);
    std::cout << "Additional code of str2: ";
    for (int i = 0; i < str2.length(); ++i) {
        std::cout << str2[str2.length() - 1 - i];
    }
    std::cout << std::endl;
    
    std::string sum;
    for (int i = 0; i < str1.length(); ++i) {
        int temp = str1[i] + str2[i];
        sum += temp % 2 + 48;
        if (i != str1.length() - 1)
            str1[i + 1] += (temp - 48*2) / 2 ;
        else if ((temp - 48 * 2) / 2 == 1) {
            sum += '1';
        }
    }
    std::cout << sum << std::endl;
    if (numStr1[0] != '-' && numStr2[0] != '-')
        sum += '0';
    if (numStr1[0] == '-' && numStr2[0] == '-')
        sum += '1';
    if (sum[sum.length() - 1] == '1') {
        ConvertAdditionalFormToReverce(sum);
        ConvertToReverseCode(sum);
    }
    std::cout << "Straight code of sum: ";
    for (int i = 0; i < sum.length(); ++i) {
        std::cout << sum[sum.length() - 1 - i];
    }
    std::cout << std::endl;
    return ConvertToTen(sum);
}

// 011010011   110010110  110010101  001101010

