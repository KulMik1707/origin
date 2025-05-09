#include <iostream>
#include "Counter.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int x;
    string y;
    char command;
    Counter coun;

    cout << "Вы хотите указать начальное значение счётчика? Введите 'da' или 'net' : ";
    cin >> y;

    if (y == "da") {
        cout << "Введите начальное значение счетчика: ";
        cin >> x;
        coun = Counter(x);
    }

    do {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
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
            cout << "До свидания!" << endl;
            return 0;
        }
    } while (true);

    return 0;
}