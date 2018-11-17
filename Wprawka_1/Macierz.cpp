#include "stdafx.h"
#include "Macierz.h"
#include <random>
#include <functional>
#include <iostream>
#include <iomanip>

using namespace std;

Macierz::Macierz(int w, int s): wysokosc(w), szerokosc(s)
{
	wartosci = new float[w*s];
	Uzupelnij();
}

Macierz::Macierz(Macierz & m):wysokosc(m.wysokosc), szerokosc(m.szerokosc)
{
	wartosci = new float[m.wysokosc * m.szerokosc];

	for (int i = 0; i < m.wysokosc * m.szerokosc; i++)
	{
		wartosci[i] = m.wartosci[i];
	}
}

Macierz::Macierz(Macierz && m):wysokosc(m.wysokosc), szerokosc(m.szerokosc), wartosci(m.wartosci)
{
	m.wartosci = nullptr;
	m.szerokosc = 0;
	m.wysokosc = 0;
}

Macierz::~Macierz()
{
	delete(wartosci);
}

void Macierz::Wypisz()
{
	int i;

	for (i = 0; i < wysokosc * szerokosc; i++)
	{
		cout << fixed << setw(8) << setprecision(2) << wartosci[i];
		if (((i + 1) % szerokosc == 0) && (i != 0))
			cout << "\n";
	}
}

Macierz Macierz::operator+(Macierz& m)
{
	int i;
	Macierz tmp(*this);
	if ((this->szerokosc == m.szerokosc) && (this->wysokosc == m.wysokosc))
	{
		for (i = 0; i < wysokosc * szerokosc; i++)
			tmp.wartosci[i] = tmp.wartosci[i] + m.wartosci[i];
		return tmp;
	}
	else
		return *this;
}

inline void Macierz::Uzupelnij()
{
	int i;
	default_random_engine generator;
	uniform_real_distribution<float> distribution(1, 100);
	auto wyznacz = bind(distribution, generator);

	for (i = 0; i < wysokosc * szerokosc; i++)
	{
		wartosci[i] = wyznacz();
	}
}

