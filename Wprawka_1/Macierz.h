#pragma once



class Macierz
{
private:
	int wysokosc, szerokosc;
	float* wartosci;

public:
	Macierz(int w, int s);
	Macierz(Macierz& m);
	Macierz(Macierz&& m);
	~Macierz();
	void Wypisz();
	Macierz operator+(Macierz& m);
private:
	void Uzupelnij();
};

