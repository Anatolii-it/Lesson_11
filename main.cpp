#include <iostream>
#include <conio.h> мені подобається пауза

using namespace std;

void deleteCharacter(char* str, int index) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    if (index >= 0 && index < len) {
        for (int i = index; i < len - 1; i++) {
            str[i] = str[i + 1];
        }
        str[len - 1] = '\0';
        cout << "   Рядок після видалення: "  << endl;
        cout << str << endl;
    }
    else {
        cout << "   Помилка: неправильний індекс" << endl;
    }
}

void deleteAllOccurrences(char* str, char ch) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int shift = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ch) {
            shift++;
        }
        else {
            str[i - shift] = str[i];
        }
    }
    str[len - shift] = '\0';
    cout << "   Рядок після видалення усіх входжень символу '" << ch << "': " << endl;
    cout << str << endl;
}

void insertCharacter(char* str, int index, char ch) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    if (index >= 0 && index <= len) {
        for (int i = len; i >= index; i--) {
            str[i + 1] = str[i];
        }
        str[index] = ch;
        cout << "   Рядок після вставки символу: "  << endl;
        cout << str << endl;
    }
    else {
        cout << "   Помилка: неправильний індекс" << endl;
    }
}

void replaceDotsWithExclamation(char* str) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int len = 0;
    while (str[len] != '\0') {
        if (str[len] == '.') {
            str[len] = '!';
        }
        len++;
    }
    cout << "   Рядок після заміни всіх крапок на знаки оклику: "  << endl;
    cout << str << endl;
}

int countOccurrences(const char* str, char ch) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            count++;
        }
        i++;
    }
    return count;
}

void countCharacters(const char* str) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int letters = 0, digits = 0, others = 0, lettersUA = 0, probel = 0;
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            letters++;
        }
        else if ((str[i] >= 'А' && str[i] <= 'Я') || (str[i] >= 'а' && str[i] <= 'я') || str[i] == 'і' || str[i] == 'I' || str[i] == 'ґ' || str[i] == 'Ґ' || str[i] == 'ї' || str[i] == 'Ї') {
            lettersUA++;
        }
        else if (str[i] == ' ') {
            probel++;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        }
        else {
            others++;
        }
        i++;
    }
    cout << "   Кількість Us літер: " << letters << endl;
    cout << "   Кількість Ua літер: " << lettersUA << endl;
    cout << "   Кількість пробелів: " << probel << endl;
    cout << "   Кількість цифр: " << digits << endl;
    cout << "   Кількість інших символів: " << others << endl;
}

void sortWordsByLength(char* str) {
    cout << "#-----------------------------------------------------------------#" << endl;

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    char* words[1000];
    int wordCount = 0;
    int wordStartIndex = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            int wordLen = i - wordStartIndex;
            words[wordCount] = new char[wordLen + 1];
            for (int j = 0; j < wordLen; j++) {
                words[wordCount][j] = str[wordStartIndex + j];
            }
            words[wordCount][wordLen] = '\0';
            wordCount++;
            wordStartIndex = i + 1;
        }
    }

    // Сортування слів
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            int len1 = 0;
            while (words[j][len1] != '\0') {
                len1++;
            }
            int len2 = 0;
            while (words[j + 1][len2] != '\0') {
                len2++;
            }
            if (len1 < len2) {
                swap(words[j], words[j + 1]);
            }
        }
    }

    cout << "   Рядок зі словами в порядку зменшення їх довжини:" << endl;
    for (int i = 0; i < wordCount; i++) {
        cout << "   " << words[i] << endl;
        delete[] words[i];
    }
}

int evaluateExpression(const char* expression) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int result = 0;
    char op = '+';
    int num = 0;

    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
        }
        else {
            if (op == '+') {
                result += num;
            }
            else {
                result -= num;
            }
            num = 0;
            if (expression[i] == '+' || expression[i] == '-') {
                op = expression[i];
            }
        }
        i++;
    }
    if (op == '+') {
        result += num;
    }
    else {
        result -= num;
    }
    return result;
}

int main() {
    int choice = 1;
    char str[1000], expression[1000];
    char ch;
    int index;


    cout << "Введіть вираз з крапками та ціфрами : " << endl;
    cin.getline(str, sizeof(str));

    while (choice != 0)
    {
        system("cls");

        cout << "                          Меню завдань:" << endl;
        cout << "1.               Видалити символ за індексом" << endl;
        cout << "2.              Видалити всі входження символу" << endl;
        cout << "3.               Вставити символ за індексом" << endl;
        cout << "4.          Замінити всі крапки на знаки оклику" << endl;
        cout << "5.         Порахувати кількість входжень символу" << endl;
        cout << "6.    Порахувати кількість літер, цифр та інших символів" << endl;
        cout << "7.              Відсортувати слова за довжиною" << endl;
        cout << "8.                 Обчислити значення виразу" << endl;
        cout << endl;
        cout << "#-----------------------------------------------------------------#" << endl;
        cout << "#              \033[1;32m  Вираз: \033[0m" << str << endl;
        cout << "#-----------------------------------------------------------------#" << endl;


        cout << "Оберіть завдання (1-8) або 0 щоб вийти: ";

        cin >> choice;
        cin.ignore(); // Очищення буфера чомусь інколи не працює

        switch (choice) {
        case 1:
            cout << "Введіть індекс: ";
            cin >> index;
            deleteCharacter(str, index);
            break;
        case 2:
            cout << "Введіть символ, який потрібно видалити: ";
            cin >> ch;
            deleteAllOccurrences(str, ch);
            break;
        case 3:
            cout << "Введіть індекс, за яким потрібно вставити символ: ";
            cin >> index;
            cout << "Введіть символ, який потрібно вставити: ";
            cin >> ch;
            insertCharacter(str, index, ch);
            break;
        case 4:
            replaceDotsWithExclamation(str);
            break;
        case 5:
            cout << "Введіть символ, кількість входжень якого потрібно порахувати: ";
            cin >> ch;
            cout << "Кількість входжень символу '" << ch << "': " << countOccurrences(str, ch) << endl;
            break;
        case 6:
            countCharacters(str);
            break;
        case 7:
            sortWordsByLength(str);
            break;
        case 8:
            cout << "Введіть вираз: ";
            cin.getline(expression, sizeof(expression));
            cout << "Результат обчислення виразу: " << evaluateExpression(expression) << endl;
            break;
        default:
            return 0;
        }
        cout << endl;
        cout << "#-----------------------------------------------------------------#" << endl;
        cout << "  Натисніть любу кнопку щоб продовжити   " << endl;
        _getch();
    }
    return 0;
}
