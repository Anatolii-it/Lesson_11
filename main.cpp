#include "functions.h"

int main() {
    int rows = 3;
    int cols = 3;
    int** array = create2DArray(rows, cols);

    fill2DArray(array, rows, cols);

    std::cout << "Початковий масив:" << std::endl;
    print2DArray(array, rows, cols);

    int newRow[] = { 9, 9, 9 };
    addRowTo2DArray(array, rows, cols, newRow);

    std::cout << "\nМасив після додавання нового рядка:" << std::endl;
    print2DArray(array, rows, cols);

    delete2DArray(array, rows);

    return 0;
}
