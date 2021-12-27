#include <iostream>
#include <string>
#include "Task_9.h"

int main()
{
    std::cout << "Enter string: ";
    std::string str;
    std::getline(std::cin, str);
    std::string newStr;
    
    std::cout << CalcSum(str, newStr);
}