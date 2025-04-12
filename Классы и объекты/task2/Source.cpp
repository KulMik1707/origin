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
	cout << "Вы хотите указать начальное значение счётчика? Введите 'da' или 'net' : ";
	cin>>y;

	if (y == "da") {
		cout << "Введите начальное значение счетчика: ";
		cin >> x;
		coun = Counter(x);
	}

	do {
		cout << "Введите команду ('+', '-', '=' или 'x'): ";
		cin >> command;

		switch (command) {

		case '+': coun.increm();
			break;

		case '-': coun.decrem();
			break;

		case '=': cout << coun.get_num();
			cout << endl;
			break;

		case 'x': cout << "До свидания!";
			return 0;
		}
	} while (true);


	return 0;
}