

#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

void deleteCharacter(string& str, int index) {
    cout << "#-----------------------------------------------------------------#" << endl;
    if (index >= 0 && index < str.length()) {
        str.erase(index, 1);
        cout << "   Рядок після видалення: " << str << endl;
        cout << endl;
    }
    else {
        cout << "   Помилка: неправильний індекс" << endl;
    }
}

void deleteAllOccurrences(string& str, char ch) {
    cout << "#-----------------------------------------------------------------#" << endl;
    size_t pos = 0;
    while ((pos = str.find(ch, pos)) != string::npos) {
        str.erase(pos, 1);
    }
    cout << "   Рядок після видалення усіх входжень символу '" << ch << "': " << str << endl;
}

void insertCharacter(string& str, int index, char ch) {
    cout << "#-----------------------------------------------------------------#" << endl;
    if (index >= 0 && index <= str.length()) {
        str.insert(index, 1, ch);
        cout << "   Рядок після вставки символу: " << str << endl;
    }
    else {
        cout << "   Помилка: неправильний індекс" << endl;
    }
}

void replaceDotsWithExclamation(string& str) {
    cout << "#-----------------------------------------------------------------#" << endl;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
    cout << "   Рядок після заміни всіх крапок на знаки оклику: " << str << endl;
}

int countOccurrences(const string& str, char ch) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

void countCharacters(const string& str) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int letters = 0, digits = 0, others = 0, lettersUA = 0, probel = 0;
    for (char c : str) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            letters++;
        }
        else if ((c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я') || c == 'і' || c == 'I' || c == 'ґ' || c == 'Ґ' || c == 'ї' || c == 'Ї') {
            lettersUA++;
        }
        else if (c == ' ') {
            probel++;
        }

        else if (c >= '0' && c <= '9') {
            digits++;
        }
        else {
            others++;
        }
    }
    cout << "   Кількість Us літер: " << letters << endl;
    cout << "   Кількість Ua літер: " << lettersUA << endl;
    cout << "   Кількість пробелів: " << probel << endl;
    cout << "   Кількість цифр: " << digits << endl;
    cout << "   Кількість інших символів: " << others << endl;
}

void sortWordsByLength(string& str) {
    cout << "#-----------------------------------------------------------------#" << endl;

    vector<string> words;

    // Розбиття на слова
    string word;
    for (unsigned char c : str) {
        if (isspace(c) || c == '.') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    // Сортування слів
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
        });

    cout << "   Рядок зі словами в порядку зменшення їх довжини:" << endl;
    for (const string& w : words) {
        cout << "   " << w << endl;
    }
}

int evaluateExpression(const string& expression) {
    cout << "#-----------------------------------------------------------------#" << endl;
    int result = 0;
    char op = '+';
    int num = 0;

    for (char c : expression) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else {
            if (op == '+') {
                result += num;
            }
            else {
                result -= num;
            }
            num = 0;
            if (c == '+' || c == '-') {
                op = c;
            }
        }
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
    //system("chcp 1251>nul");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    int choice = 1;
    string str, expression;
    char ch;
    int index;


    cout << "Введіть вираз з крапками та ціфрами \033[1;31m (Бажано англійскою декілька різних за довжиною слів): \033[0m " << endl;
    getline(cin, str);

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
            getline(cin, expression);
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
