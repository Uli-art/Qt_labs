#include <iostream>
#include "Task_4.h"

int main()
{
    std::string str1;
    str1 = InputValidation();
    //std::cin >> str1;
    std::string str2;
    str2 = InputValidation();
    //std::cin >> str2;
    char sign;
    std::cin >> sign;
    std::cout << Output(str1, str2, sign);
}