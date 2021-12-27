#include <iostream>
#include <cmath>
#include< string>
#include <cstdint>


int Length(std::uint64_t temp) {
    int count = 0;
    while (temp > 0) {
        temp /= 10;
        ++count;
    }
    return count;
}

std::string Reverse(std::string str) {

    std::string reverseStr;
    for (int i = 0; i < str.length(); ++i) {
        reverseStr += str[str.length() - 1 - i];
    }
    return reverseStr;
}
/*
std::string DivitionBy2(std::string& str) {
    if (atoi(str.c_str()) <= 18446744073709551615) {
        unsigned long long int temp = atoi(str.c_str());
        temp /= 2;
        str = std::to_string(temp);
        return str;
    }
    else {
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
}*/

bool find(std::string a, std::string findEl) {
    a = Reverse(a);
    int j = 0;
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
    }
    return false;
}
// 10001001 111000000
bool convertNew( std::uint64_t str) {
    std::string binary;
    int findNumLen = Length(str);
    std::uint64_t temp = 1;
    std::uint64_t str2 = str;
    for (int i = 0; i < findNumLen; ++i) {
        if (str2 & temp) {
            if (str % 10 != 1)
                return false;
        }
        else {
            if (str % 10 != 0)
                return false;
        }
        str /= 10;
        temp = temp << 1;
    }
    return true;
}

/*void Plustwo(std::string& findNum){
    findNum = Reverse(findNum);
    findNum[0] += 2;
    int i = 0;
    while (findNum[i] == '2' || findNum[i] == '3') {
        if (findNum[i] == '3') {
            findNum[i] = '1';
        }
        else {
            findNum[i] = '0';
        }
        if (i == findNum.length() - 1) {
            findNum += '1';
            break;
        }
        else {
            findNum[i + 1] += 1;
        }
        i++;
    }
    findNum = Reverse(findNum);
}*/

std::uint64_t Plus(std::uint64_t& num) {
    std::uint64_t temp = 1;
    int count = 0;
    while (num & temp) {
        num -= pow(10, count);
        temp = temp << 1;
        ++count;
    }
    num += pow(10, count);
    return num;
}

std::uint64_t Decimal(int num) {
    int count = 1;
    std::uint64_t findNum = 10;
    if (num == 1) {
        return 1;
    }
        while ((count) != num ) {  
            std::cout << findNum;
            if (convertNew(findNum)) {
                
                count += 1;
            }
            else {

                std::cout << " ------";
            }
            if (count != num) {
                Plus(findNum);
            }
            std::cout << std::endl;
        }
    return findNum;
}

int main()
{
    std::cout << "Enter number\n";
    int num;
    std::cin >> num;
    std::cout << Decimal(num);
    //double n = 10;
   // std::cout << find("oierwq","re");
}


/*


std::string erase(int pos, int count, std::string& num) {
    std::string newNum;

    for (int i = 0; i < num.length(); ++i) {

        if (i >= pos && i < count) {

            ++i;
        }
        newNum += num[i];
    }
    return newNum;
}


double temp = atof(findNum.c_str());
            std::string converted = std::bitset<100>(temp).to_string();
            int i;
            for (i = 0; converted[i] == '0'; ++i);
                converted = erase(0, i, converted);

double temp = atof(findNum.c_str());
            std::string converted = std::bitset<100>(temp).to_string();
            int i;
            for (i = 0; converted[i] == '0'; ++i);
            converted = erase(0, i, converted);


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
    }
    return false;
}

bool IsAllZero(std::string num) {
    for (int i = 1; i < num.length(); ++i) {
        if (num[i] == '0') {}
        else {
            return false;
        }
    }
    return true;
}

std::string ConvertToBinaryCode(std::string str1) {
    std::string str;
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

*/