#include "functions.h"


int** create2DArray(int rows, int cols) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    return array;
}

void fill2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = i * cols + j;
        }
    }
}

void print2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void addRowTo2DArray(int**& array, int& rows, int cols, int* newRow) {
    int** newArray = new int* [rows + 1];
    newArray[0] = newRow;
    for (int i = 0; i < rows; ++i) {
        newArray[i + 1] = array[i];
    }
    delete[] array;
    array = newArray;
    ++rows;
}



void delete2DArray(int** array, int rows) {
    for (int i = -1; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

