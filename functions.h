#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>

int** create2DArray(int rows, int cols);
void fill2DArray(int** array, int rows, int cols);
void print2DArray(int** array, int rows, int cols);
void addRowTo2DArray(int**& array, int& rows, int cols, int* newRow);
void delete2DArray(int** array, int rows);

#endif
