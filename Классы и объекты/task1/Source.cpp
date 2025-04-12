#include<iostream>
#include<string>

using namespace std;

class Calculator
{
private:
	double num1;
	double num2;

public:
	double add() {
		return num1 + num2;
	}
	double multiply() {
		return num1 * num2;
	}

	double subtract_1_2() {
		return num1 - num2;
	}

	double subtract_2_1() {
		return num2 - num1;
	}

	double divide_1_2() {
		return num1 / num2;
	}

	double divide_2_1() {
		return num2 / num1;
	}

	bool set_num1(double num1) {
		if (num1 == 0.0) {
			return false;
		}
		else {
			this->num1 = num1;
			return true;
		}
	
	}

	bool set_num2(double num2) {
		if (num2 == 0.0) {
			return false;
		}
		else {
			this->num2 = num2;
			return true;
		}
	}

};

int main() {
	setlocale(LC_ALL, "Rus");
	Calculator calc{};
	double x1{};
	double x2{};

	do {
		cout << "Введите num1: ";
		cin >> x1;

		if (!calc.set_num1(x1)) {
			cout << "Неверный ввод!" << endl;
		}
		else  break ;
	} while (true);

	do {
		cout << "Введите num2: ";
		cin >> x2;

		if (!calc.set_num2(x2)) {
			cout << "Неверный ввод!" << endl;
		}
		else  break;
	} while (true);

	cout << "num1 + num2 = " << calc.add() << endl;
	cout << "num1 * num2 = " << calc.multiply() << endl;
	cout << "num1 - num2 = " << calc.subtract_1_2() << endl;
	cout << "num2 - num1 = " << calc.subtract_2_1() << endl;
	cout << "num1 / num2 = " << calc.divide_1_2() << endl;
	cout << "num2 / num1 = " << calc.divide_2_1() << endl;
	return 0;
}
	

