#include <iostream>
#include "functions.h"

int main() {
    int rows = 3;
    int cols = 3;
    int** array = create2DArray(rows, cols);

    // Заповнення масиву початковими значеннями
    fill2DArray(array, rows, cols);

    // Вивід початкового масиву
    std::cout << "Початковий масив:" << std::endl;
    print2DArray(array, rows, cols);

    // Додавання нового рядка
    int newRow[] = { 9, 9, 9 };
    addRowTo2DArray(array, rows, cols, newRow);

    // Вивід масиву після додавання рядка
    std::cout << "\nМасив після додавання нового рядка:" << std::endl;
    print2DArray(array, rows, cols);

    // Звільнення пам'яті
    delete2DArray(array, rows - 1);

    return 0;
}
