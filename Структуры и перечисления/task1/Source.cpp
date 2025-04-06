#include <iostream>
#include <string>

using namespace std;

enum Month {
    J = 1,
    F,
    M,
    AP,
    May,
    Jun,
    Jul,
    Aug,
    S,
    O,
    N,
    D
};


string Monthout( Month mon) {
    switch (mon) {
    case J: return "Январь";
    case F: return "Февраль";
    case M: return "Март";
    case AP: return "Апрель";
    case May: return "Май";
    case Jun: return "Июнь";
    case Jul: return "Июль";
    case Aug: return "Август";
    case S: return "Сентябрь";
    case O: return "Октябрь";
    case N: return "Ноябрь";
    case D: return "Декабрь";
    default: break;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int x;

    while (true) {
        cout << "Введите номер месяца: ";
        cin >> x;

        if (x == 0) {
            cout << "До свидания!" << endl;
            break;
        }

        if (x < 1 || x > 12) {
            cout << "Неправильный номер!" << endl;
            continue;
        }

        Month mon = static_cast<Month>(x);
        cout << Monthout(mon) << endl;
    }

    return 0;
}