#include "functions.h"
#include <iostream>

// Функція для створення двовимірного масиву
int** create2DArray(int rows, int cols) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    return array;
}

// Функція для заповнення двовимірного масиву
void fill2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = i * cols + j;
        }
    }
}

// Функція для виведення двовимірного масиву
void print2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


// Функція для додавання рядка до початку двовимірного масиву
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


// Функція для видалення двовимірного масиву
void delete2DArray(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

