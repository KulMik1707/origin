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
    case J: return "������";
    case F: return "�������";
    case M: return "����";
    case AP: return "������";
    case May: return "���";
    case Jun: return "����";
    case Jul: return "����";
    case Aug: return "������";
    case S: return "��������";
    case O: return "�������";
    case N: return "������";
    case D: return "�������";
    default: break;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int x;

    while (true) {
        cout << "������� ����� ������: ";
        cin >> x;

        if (x == 0) {
            cout << "�� ��������!" << endl;
            break;
        }

        if (x < 1 || x > 12) {
            cout << "������������ �����!" << endl;
            continue;
        }

        Month mon = static_cast<Month>(x);
        cout << Monthout(mon) << endl;
    }

    return 0;
}