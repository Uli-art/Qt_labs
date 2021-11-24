#pragma once

#include <iostream>
int getValue();
void DeleteArrays(int** arr, int size, int* newArray);
void FillArray(int** arr, const int size1, const int size2);
void ShowArray(int** const arr, const int size1, const int size2);
void ShowArray(int* const arr, const int size);
int Min(int size1, int size2);
void Array(int** const arr, int* newArray, int size, int& realSize);
int MultEl(int* arr, int realSize);
