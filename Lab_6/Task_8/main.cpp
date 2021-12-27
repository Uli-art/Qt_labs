#include <iostream>
#include <string>
#include "Task_8.h"

int main()
{
    std::cout << "Enter 1 string:\n";
    std::string str1;
    getline(std::cin, str1);
    std::cout << "Enter 2 string:\n";
    std::string str2;
    getline(std::cin, str2);
    std::string newStr;
    std::string answer;
    int start = FindFirstEl(str1, str2);
    int position = 1;

    std::cout << getAnswer(newStr, start, str1, str2, position);
    return 0;
}