#include <iostream>

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void addRowToBeginning(int arr[MAX_ROWS][MAX_COLS], int& rows, int cols, int rowToAdd[MAX_COLS]) {
    if (rows >= MAX_ROWS) {
        std::cout << "Масив повний, рядок не може бути доданий.\n";
        return;
    }
    for (int i = rows; i > 0; i--) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i - 1][j];
        }
    }
    for (int j = 0; j < cols; j++) {
        arr[0][j] = rowToAdd[j];
    }
    rows++;
}

void addRowToPosition(int arr[MAX_ROWS][MAX_COLS], int& rows, int cols, int rowToAdd[MAX_COLS], int position) {
    if (rows >= MAX_ROWS) {
        std::cout << "Масив повний, рядок не може бути доданий.\n";
        return;
    }
    if (position < 0 || position > rows) {
        std::cout << "Неправильна позиція для вставки.\n";
        return;
    }
    for (int i = rows; i > position; i--) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i - 1][j];
        }
    }
    for (int j = 0; j < cols; j++) {
        arr[position][j] = rowToAdd[j];
    }
    rows++;
}

void deleteRow(int arr[MAX_ROWS][MAX_COLS], int& rows, int cols, int position) {
    if (position < 0 || position >= rows) {
        std::cout << "Неправильна позиція для видалення.\n";
        return;
    }
    for (int i = position; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    rows--;
}

void printArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int arr[MAX_ROWS][MAX_COLS];
    int rows, cols;

    std::cout << "Введіть кількість рядків і стовпців: ";
    std::cin >> rows >> cols;

    std::cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> arr[i][j];
        }
    }

    std::cout << "Початковий масив:\n";
    printArray(arr, rows, cols);

    int rowToAdd[MAX_COLS];
    std::cout << "Введіть рядок для додавання: ";
    for (int j = 0; j < cols; j++) {
        std::cin >> rowToAdd[j];
    }

    addRowToBeginning(arr, rows, cols, rowToAdd);
    std::cout << "Масив після додавання рядка в початок:\n";
    printArray(arr, rows, cols);

    int position;
    std::cout << "Введіть позицію для додавання рядка: ";
    std::cin >> position;

    std::cout << "Введіть рядок для додавання: ";
    for (int j = 0; j < cols; j++) {
        std::cin >> rowToAdd[j];
    }

    addRowToPosition(arr, rows, cols, rowToAdd, position);
    std::cout << "Масив після додавання рядка на позицію " << position << ":\n";
    printArray(arr, rows, cols);

    std::cout << "Введіть номер рядка для видалення: ";
    std::cin >> position;

    deleteRow(arr, rows, cols, position);
    std::cout << "Масив після видалення рядка " << position << ":\n";
    printArray(arr, rows, cols);

    return 0;
}
