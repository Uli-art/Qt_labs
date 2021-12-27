#pragma once
#include <iostream>
#include <string>

int FindFirstEl(std::string str1, std::string str2);
bool GoRight(std::string str2, int start, std::string str1, int position);
bool GoLeft(std::string str2, int start, std::string str1, int position);
std::string getAnswer(std::string& newStr, int start, std::string& str1, std::string& str2, int& position);