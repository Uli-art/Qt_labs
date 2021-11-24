// Task_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int findNum(int number, int position, int count) {
    int element;
    if (position > count) return -1;
    for (int i = 0; i <= position; ++i) {
        element = number % 10;
        number /= 10;
    }
    return element;
}
int main()
{
    int number;
    std::cout << "Enter number:";
    std::cin >> number;
    int count = 0;
    int temp = number;
    while (temp != 0) {
        temp /= 10;
        ++count;
    }
    std::cout << count << std::endl;
    std::cout << "Enter position:\n";
    int position;
    std::cin >> position;
    std::cout << findNum(number, position, count);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
