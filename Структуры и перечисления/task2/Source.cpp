#include<iostream>
#include<string>

using namespace std;

struct personaldata
{
	int schetnumber;
	string name;
	double balance;
};

void changebalance(personaldata& P, double newbalance)
{
	P.balance = newbalance;
}

int main() 
{
	setlocale(LC_ALL, "Rus");
	personaldata x;
	double bal;
	cout << "¬ведите номер счета: ";
	cin >> x.schetnumber;
	cout << endl;

	cout << "¬ведите им€ владельца: ";
	cin >> x.name;
	cout << endl;

	cout << "¬ведите баланс: ";
	cin >> x.balance;
	cout << endl;

	cout << "¬ведите новый баланс: ";
	cin >> bal;
	changebalance(x, bal);
	cout << x.name << ", " << x.schetnumber << ", " << x.balance << endl;
	return 0;

}