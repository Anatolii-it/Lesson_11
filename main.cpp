#include "functions.h"

int main() {
    int rows = 3;
    int cols = 3;
    int** array = create2DArray(rows, cols);

    fill2DArray(array, rows, cols);

    cout << "Початковий масив:" << std::endl;
    print2DArray(array, rows, cols);

    int newRow[] = { 9, 9, 9 };
    addRowTo2DArray(array, rows, cols, newRow);

    cout << "Перше завдання додати рядок у двовимірному масиву в початок" << std::endl;
    cout << "\nМасив після додавання нового рядка:" << std::endl;
    print2DArray(array, rows, cols);

    
    int position;
    int new1Row[] = { 2, 2, 2 };
    cout << "Друге завдання додати рядок в двовимірний масив у зазначену позіцію " << std::endl;
    cout << "Ведіть позіцію додавання рядка - ";
    cin >> position;
    

    addRowToP2DArray(array, rows, cols, new1Row, position);
    //cout << "Масив після додавання рядка на позицію " << position << ":\n";
    print2DArray(array, rows, cols);

    cout << std::endl;
    cout << "Трете завдання вилучення рядка з двовимірного масиву з зазначеної позіції " << std::endl;
    cout << "Ведіть позіцію для вилучення рядка - ";
    //cin.ignore(); якщо ввести два рази однакові значення чомусь видає помилку буферу 
    cin >> position;
    deleteRowFrom2DArray(array, rows, cols, position);
    print2DArray(array, rows, cols);

    delete2DArray(array, rows);

    return 0;
}