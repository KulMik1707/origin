#include<string>
#include<iostream>
using namespace std;

struct Adres {
	string city;
	string street;
	int nomberhouse;
	int nomberflat;
	int index;
};

void printAdres(Adres& x)
{
	cout << "�����: " << x.city << endl;
	cout << "�����: " << x.street << endl;
	cout << "����� ����: " << x.nomberhouse << endl;
	cout << "����� ��������: " << x.nomberflat << endl;
	cout << "������: " << x.index << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Adres adr1
	{
		"������",
		"�����",
		12,
		8,
		123456
	};

	Adres adr2
	{
		"������",
		"�������",
		59,
		143,
		953769
	};
	printAdres(adr1);
	cout << endl;
	printAdres(adr2);
	return 0;

}