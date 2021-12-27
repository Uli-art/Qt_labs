#include <iostream>
#include "Task_7.h"

int main()
{
    std::cout << "Enter number\n";
    int num;
    std::cin >> num;
    int divider;
    std::cin >> divider;
    bool isDivisible;
    isDivisible = Division(num, divider);
    if(isDivisible)
        std::cout << num << " is divisible by " << divider << "\n";
    else
        std::cout << num << " is not divisible by " << divider << "\n";
}