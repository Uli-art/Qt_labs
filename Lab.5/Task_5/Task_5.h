#pragma once
#include <iostream> 
int getValue();
void FillArray(int** arr, const int size1, const int size2);
void ShowArray(int** const arr, const int size1, const int size2);
void ShowArray(int* const arr, int size);
void DeleteArray(int** arr, int size);
int* FindEl(int** const arr, int size1, int size2, int& sizeNewArray);
double Average(int* newArray, int sizeNewArray);