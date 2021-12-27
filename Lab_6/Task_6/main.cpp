// Task_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include"Task_6.h"
int main()
{
    std::cout << "Enter wold(not more than 14 letters): \n";
    std::string word;

    std::getline(std::cin, word);
    if (ThereDuplicateLetters(word)) {
        int elOfArrray = 0;
        int* arr = CountOfDupicateLetters(word, elOfArrray);
        std::cout << CountOfAnagramsSek(word, arr, elOfArrray);

    }
    else {
        std::cout << CountOfAnagrams(word);
    }
}
