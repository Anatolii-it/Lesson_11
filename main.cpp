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
        cout << "   ����� ���� ���������: " << str << endl;
        cout << endl;
    }
    else {
        cout << "   �������: ������������ ������" << endl;
    }
}

void deleteAllOccurrences(string& str, char ch) {
    cout << "#-----------------------------------------------------------------#" << endl;
    size_t pos = 0;
    while ((pos = str.find(ch, pos)) != string::npos) {
        str.erase(pos, 1);
    }
    cout << "   ����� ���� ��������� ��� �������� ������� '" << ch << "': " << str << endl;
}

void insertCharacter(string& str, int index, char ch) {
    cout << "#-----------------------------------------------------------------#" << endl;
    if (index >= 0 && index <= str.length()) {
        str.insert(index, 1, ch);
        cout << "   ����� ���� ������� �������: " << str << endl;
    }
    else {
        cout << "   �������: ������������ ������" << endl;
    }
}

void replaceDotsWithExclamation(string& str) {
    cout << "#-----------------------------------------------------------------#" << endl;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
    cout << "   ����� ���� ����� ��� ������ �� ����� ������: " << str << endl;
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
    int letters = 0, digits = 0, others = 0;
    for (char c : str) {
        if (isalpha(c)) {
            letters++;
        }
        else if (isdigit(c)) {
            digits++;
        }
        else {
            others++;
        }
    }
    cout << "   ʳ������ ����: " << letters << endl;
    cout << "   ʳ������ ����: " << digits << endl;
    cout << "   ʳ������ ����� �������: " << others << endl;
}

void sortWordsByLength(string& str) {
    cout << "#-----------------------------------------------------------------#" << endl;
    
    vector<string> words;

    // �������� �� �����
    string word;
    for (char c : str) {
        if (isspace(c)) {
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

    // ���������� ���
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
        });

    cout << "   ����� � ������� � ������� ��������� �� �������:" << endl;
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice = 1;
    string str, expression;
    char ch;
    int index;
    

    cout << "������ �����: ";
    getline(cin, str);
    
    while (choice != 0)
    {
        system("cls");

        cout << "                          ���� �������:" << endl;
        cout << "1.               �������� ������ �� ��������" << endl;
        cout << "2.              �������� �� ��������� �������" << endl;
        cout << "3.               �������� ������ �� ��������" << endl;
        cout << "4.          ������� �� ������ �� ����� ������" << endl;
        cout << "5.         ���������� ������� �������� �������" << endl;
        cout << "6.    ���������� ������� ����, ���� �� ����� �������" << endl;
        cout << "7.              ³���������� ����� �� ��������" << endl;
        cout << "8.                 ��������� �������� ������" << endl;
        cout  << endl;
        cout << "#-----------------------------------------------------------------#" << endl;
        cout << "������ �������� (1-8) ��� 0 ��� �����: ";
        
        cin >> choice;
        cin.ignore(); // �������� ������

        switch (choice) {
        case 1:
            cout << "������ ������: ";
            cin >> index;
            deleteCharacter(str, index);
            break;
        case 2:
            cout << "������ ������, ���� ������� ��������: ";
            cin >> ch;
            deleteAllOccurrences(str, ch);
            break;
        case 3:
            cout << "������ ������, �� ���� ������� �������� ������: ";
            cin >> index;
            cout << "������ ������, ���� ������� ��������: ";
            cin >> ch;
            insertCharacter(str, index, ch);
            break;
        case 4:
            replaceDotsWithExclamation(str);
            break;
        case 5:
            cout << "������ ������, ������� �������� ����� ������� ����������: ";
            cin >> ch;
            cout << "ʳ������ �������� ������� '" << ch << "': " << countOccurrences(str, ch) << endl;
            break;
        case 6:
            countCharacters(str);
            break;
        case 7:
            sortWordsByLength(str);
            break;
        case 8:
            cout << "������ �����: ";
            //cin.ignore(); // �������� ������ ��������
            getline(cin, expression);
            cout << "��������� ���������� ������: " << evaluateExpression(expression) << endl;
            break;
        default:
            return 0;
        }
        cout  << endl;
        cout << "#-----------------------------------------------------------------#" << endl;
        cout << "  �������� ���� ������ ��� ����������   " << endl;
        _getch();
    }
    return 0;
}
