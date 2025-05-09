#include <iostream>
#include "Counter.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int x;
    string y;
    char command;
    Counter coun;

    cout << "�� ������ ������� ��������� �������� ��������? ������� 'da' ��� 'net' : ";
    cin >> y;

    if (y == "da") {
        cout << "������� ��������� �������� ��������: ";
        cin >> x;
        coun = Counter(x);
    }

    do {
        cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
        cin >> command;

        switch (command) {
        case '+':
            coun.increm();
            break;
        case '-':
            coun.decrem();
            break;
        case '=':
            cout << coun.get_num() << endl;
            break;
        case 'x':
            cout << "�� ��������!" << endl;
            return 0;
        }
    } while (true);

    return 0;
}