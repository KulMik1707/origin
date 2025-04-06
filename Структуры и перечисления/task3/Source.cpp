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
	cout << "Город: " << x.city << endl;
	cout << "Улица: " << x.street << endl;
	cout << "Номер дома: " << x.nomberhouse << endl;
	cout << "Номер квартиры: " << x.nomberflat << endl;
	cout << "Индекс: " << x.index << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Adres adr1
	{
		"Москва",
		"Арбат",
		12,
		8,
		123456
	};

	Adres adr2
	{
		"Ижевск",
		"Пушкина",
		59,
		143,
		953769
	};
	printAdres(adr1);
	cout << endl;
	printAdres(adr2);
	return 0;

}