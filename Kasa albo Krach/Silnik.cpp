#include "Silnik.h"
#include <vector>
#include <ctime>
#include <random>
#include <iostream>
#include <memory>

long double Silnik::losujWspolczynnikZmianyCeny() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<long double> dis(0.6, 1.4);
	return dis(gen);
}
void Silnik::losujCenyAkcji(std::vector<Firma>& firma, long double q) {
	for (int i = 0; i < firma.size(); i++) {
		long double p = losujWspolczynnikZmianyCeny();
		long double a = firma[i].getAkcja().getCena() * p * q;
		firma[i].getAkcja().setCena(a);
	}
}
void Silnik::start() {
	srand(time(NULL));
	Kredyt kredytpeKO(0, 1, 2, 0);
	Bank peKO("PeKO", 1, kredytpeKO);
	auto ulica = std::make_shared<Ulica>();

	lokacja = ulica;
	short wybor;
	int startowaKasa = 0;
	wyswietlacz.ekranPowitalny();
	wyswietlacz.poczatekGry();
	wyswietlacz.uzueplnijDane1();
	std::string nazwa;
	std::cin >> nazwa;
	wyswietlacz.uzueplnijDane2();
	long double cel;
	std::cin >> cel;
	wyswietlacz.wybierzPoziomTrudnosci();
	std::cin >> wybor;
	switch(wybor) {
	case 1:
		startowaKasa = 1000;
		break;
	case 2:
		startowaKasa = 500;
		break;
	case 3:
		startowaKasa = 100;
		break;
	default:
		std::cout << "Niepoprawny wybór, ustawiam poziom trudności na łatwy." << std::endl;
		startowaKasa = 1000;
		break;
	};
	Gracz gracz(0, startowaKasa, nazwa, cel);
	glownaPetla();
}
void Silnik::glownaPetla() {
	while (true) {
		lokacja->wejdz(wyswietlacz, gracz);
	}
}