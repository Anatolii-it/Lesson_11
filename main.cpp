#include <iostream>

using namespace std;

void inputResults(double*** results, int N, int* M) {
    for (int i = 0; i < N; ++i) {
        cout << "Введіть кількість оцінок для студента " << i + 1 << ": ";
        cin >> M[i];
        results[i] = new double* [M[i]];
        cout << "Введіть оцінки для студента " << i + 1 << ":\n";
        for (int j = 0; j < M[i]; ++j) {
            results[i][j] = new double;
            cout << "Оцінка за предмет " << j + 1 << ": ";
            cin >> *results[i][j];
        }
    }
}

void calculateAverage(double*** results, int N, int* M) {
    for (int i = 0; i < N; ++i) {
        double sum = 0;
        for (int j = 0; j < M[i]; ++j) {
            sum += *results[i][j];
        }
        cout << "Середня успішність для студента " << i + 1 << ": " << sum / M[i] << endl;
    }
}

void deleteResults(double*** results, int N, int* M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M[i]; ++j) {
            delete results[i][j];
        }
        delete[] results[i];
    }
    delete[] results;
    delete[] M;
}

int main() {
    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    int* M = new int[N];
    double*** results = new double** [N];

    inputResults(results, N, M);
    calculateAverage(results, N, M);
    deleteResults(results, N, M);

    return 0;
}
