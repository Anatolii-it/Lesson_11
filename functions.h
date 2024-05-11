#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>

using namespace std;


int** create2DArray(int rows, int cols);
void fill2DArray(int** array, int rows, int cols);
void print2DArray(int** array, int rows, int cols);
void addRowTo2DArray(int**& array, int& rows, int cols, int* newRow);
void addRowToP2DArray(int**& array, int& rows, int cols, int* new1Row, int position);
void deleteRowFrom2DArray(int**& array, int& rows, int cols, int position);
void delete2DArray(int** array, int rows);

#endif