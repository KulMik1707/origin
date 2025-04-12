#include<iostream>

using namespace std;

class Counter {
private:
	int num;

public:
	Counter():num(1){}

	Counter(int numb) :num(numb) {};
	

	void increm() {
		++num;
	}

	void decrem() {
		--num;

	}
	int get_num() {
		return num;
	}
};

int main() {

	setlocale(LC_ALL, "Russian");

	int x;
	string y;
	char command;
	Counter coun;
	cout << "�� ������ ������� ��������� �������� ��������? ������� 'da' ��� 'net' : ";
	cin>>y;

	if (y == "da") {
		cout << "������� ��������� �������� ��������: ";
		cin >> x;
		coun = Counter(x);
	}

	do {
		cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		cin >> command;

		switch (command) {

		case '+': coun.increm();
			break;

		case '-': coun.decrem();
			break;

		case '=': cout << coun.get_num();
			cout << endl;
			break;

		case 'x': cout << "�� ��������!";
			return 0;
		}
	} while (true);


	return 0;
}