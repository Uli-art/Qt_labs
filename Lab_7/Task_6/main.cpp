#include <iostream>
#include "Task_6.h"

int main()
{
    std::cout << "Enter count\n";
    int count;
    std::cin >> count;
    int i = 0;
    while (i < count) {
        int number;
        std::cin >> number;
        std::cout << "Count of intresting numbers: " << FcountOfIntrNum(number) << std::endl;
        ++i;
    }
}