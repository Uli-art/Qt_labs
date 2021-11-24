#pragma once
#include <iostream>
int getValue();
void FillArray(double** arr, const int size1, const int size2);
void ShowArray(double** const arr, const int size1, const int size2);
void DeleteArray(double** arr, int size);
void FindZeroElements(double** arr, int size1, int size2, int& countOfZeroEl);
void TransformArray(double** arr, int size1, int size2);