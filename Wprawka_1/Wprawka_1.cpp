// Wprawka_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>


using namespace std;

void Zadanie1()
{
	int i = 0;

	for (i = 0; i < 255; i++)
	{
		cout << i << " " << (char)i << "\n";
		if (i % 10 == 11)
		{
			cout << "\n";
		}
	}
}

void Zadanie2(const long long int& check)
{
	list<int> dzielniki;
	bool primeNumber = true, deviderCheck = true;
	long long int devider = 2, tmp = check;

	while ((devider <= (tmp / 2)))
	{
		if (tmp % devider == 0)
		{
			tmp = tmp / devider;
			dzielniki.push_front(devider);
		}			
		else 
			devider++;
	}

	if (dzielniki.empty())
		cout << "Liczba pierwsza\n";
	else
		while (!dzielniki.empty())
		{
			cout << dzielniki.back() << "\n";
			dzielniki.pop_back();
		}	 
}

void Zadanie3(double& variable)
{

	double x1 = variable, x0 = variable;

	do
		x1 = (x0 + variable / x0) / 2;
	while (x1 - x0 < 1);

	variable = x1;
	//x1 = podana liczba;
	//x{ i + 1 } = (x{ i } +podana_liczba / x_{ i }) / 2;
	//Deklaracja funkcji jest nastêpuj¹ca :
	//void pierwiastek(<typ> liczba);
	//Jaki powinien byæ typ zmiennej przekazanej do funkcji je¿eli chcemy skorzystaæ z wyniku ?
	cout << "Zadanie 3: " << variable << "\n";
}


int main()
{
	double i = 100;
	//Zadanie2(6321246989923);
	Zadanie3(i);
    return 0;
}

