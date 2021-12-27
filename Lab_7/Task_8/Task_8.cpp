// Task_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

int Length(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        ++count;
    }
    return count;
}

bool IsIt0or1(std::string num) {
    for (int i = 0; i < num.length(); ++i) {
        if (num[i] == '1' || num[i] == '0') {
        }
        else {
            return false;
        }
    }
    return true;
}

std::string Reverse(std::string str) {

    std::string reverseStr;
    for (int i = 0; i < str.length(); ++i) {
        reverseStr += str[str.length() - 1 - i];
    }
    return reverseStr;
}

std::string ConvertToBinary(int num) {
    std::string converted;
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            converted += '1';
        }
        else {
            converted += '0';
        }
        num /= 2;
        ++count;
    }
    return converted;
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

            if (convert != 0)
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

    while (!(str == "0")) {
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

bool ConvertAndConpare(std::string str1, std::string findNum) {

    std::string bianarystr;
    int convert = 0;
    int count = 0;
    int lenFindNum = findNum.length();
    while (count != lenFindNum) {
        convert = (int)str1[str1.length() - 1] - 48;
        if (convert % 2 == 0) {
            bianarystr += 48;
        }
        else {
            bianarystr += 49;
        }
        if (findNum[lenFindNum - count - 1] != bianarystr[count]) {
            return false;
        }
        std::string temp = str1;
        str1 = DivitionBy2(temp);
        ++count;
    }
    return true;
}

bool IsAllOnes(std::string num) {
    for (int i = 0; i < num.length(); ++i) {
        if (num[i] == '1') {}
        else {
            return false;
        }
    }
    return true;
}

bool find(std::string a, std::string findEl) {
    int j = 0;
    int pos;
    bool isPos = true;
    int len = a.length() - findEl.length();
    size_t lenFindEl = findEl.length();
    for (int i = 0; i <= len; ++i) {
        isPos = true;
        if (a[i] == findEl[0]) {
            for (int j = 1; j < findEl.length(); ++j) {
                if (a[i + j] != findEl[j]) {
                    isPos = false;
                    break;
                }
            }
        }
        else { isPos = false; }
        if (isPos) {
            return true;
        }

        /* for (j = 0; a[i + j] == findEl[j]; ++j) {
            if (j == lenFindEl - 1)
                return true;
        }*/
    }
    return false;
}
bool finds(std::string converted, std::string findNum) {
    bool ThisNum = true;

    int lenNum = findNum.length();
    int lenConv = converted.length();
    for (int i = 0; i < lenNum; ++i) {
        if (findNum[lenNum - i - 1] - 48 != converted[lenConv - i - 1] - 48) {
            ThisNum = false;
            break;
        }
    }
    return ThisNum;
}

void Plus(std::string& findNum) {
    int i = findNum.length();
    int j = 0;
    while (j < i && findNum[i - j - 1] == '1') {
        findNum[i - j - 1] = '0';
        ++j;
    }
    if (j != i) {
        findNum[i - j - 1] = '1';
    }
    else {
        findNum = '1' + findNum;
    }
}

// 101000 1000
std::string Decimal(int num) {
    int count = 0;
    std::string findNum = "1";
    std::string result;
    bool ThisNum = true;
    while (count != num) {
        
           //ThisNum = true;
           // std::string converted = Reverse(ConvertToBinaryCode(findNum));
          //  result = findNum;
            /* int lenNum = findNum.length();
            int lenConv = converted.length();
            for (int i = 0; i < lenNum; ++i) {
                if (findNum[lenNum - i - 1] - 48 != converted[lenConv - i - 1] - 48) {
                    ThisNum = false;
                    break;
                }
            }*/
            if (ConvertAndConpare(findNum, findNum)) {
                //result = findNum;
                ++count;
            }
            
            if (count != num) {
                Plus(findNum);
                int len = findNum.length();
                if (findNum[len - 1] == '0' && findNum[len - 2] == '1' && count > 8) {
                    Plus(findNum);
                    Plus(findNum);
                }
            }
        /*if (IsAllOnes(findNum)) {
            int len = findNum.length();
            findNum = "1";
            for (int i = 0; i < len; ++i) {
                findNum += '0';
            }
        }
        else {
            findNum[findNum.length() - 1] += 1;
            while (!IsIt0or1(findNum)) {
                findNum[findNum.length() - 1] += 1;
                for (int i = findNum.length() - 1; i > 0; --i) {
                    if (findNum[i] - 48 > 9) {
                        findNum[i] = '0';
                        if (i == 0) {
                            findNum = Reverse(findNum);
                            findNum += '1';
                            findNum = Reverse(findNum);
                        }
                        else
                        {
                            findNum[i - 1] += 1;
                        }
                    }
                }
            }
        }*/
          /*  if (count != num) {
                findNum = Reverse(findNum);
                if (findNum[0] == '0') {
                    findNum[0] = '1';
                }
                else {
                    int i = 1;
                    findNum[0] = '0';
                    if (i != findNum.length())
                        findNum[i] += 1;
                    else {
                        findNum += '1';
                    }

                    while (findNum[i] == '2') {
                        findNum[i] = '0';
                        if (i == findNum.length() - 1) {
                            findNum += '1';
                            break;
                        }
                        if (findNum[i + 1] == '1') {
                            findNum[i + 1] = '2';
                        }
                        else {
                            findNum[i + 1] += 1;
                        }
                        i++;
                    }
                }
            }*/
            
        /*if (findNum[findNum.length() - 2] == '2')
            findNum[findNum.length() - 2] = '0';*/
       // findNum = Reverse(findNum);
    }
    return findNum;
}
// 02






/*
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
            if (str[i + 1] == '1')
                str[i + 1] = '2';
            i++;
        }
    }
    if (str[str.length() - 2] == '2')
        str[str.length() - 2] = '0';
    return str;
}
*/ 