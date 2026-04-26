#include "Silnik.h"
#include <vector>
#include <ctime>
#include <random>
#include <iostream>
#include <memory>
#include <stdlib.h>

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
float Silnik::losujOprocentowanie() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0.01, 0.2);
	return dis(gen);
}
int Silnik::losujCzasKredytu() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(6, 40);
	return dis(gen);
}
float Silnik::losujStawkeKary(Bank& bank) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0.05, 0.15);
	return dis(gen);
}
void Silnik::losujOferteBanku(Bank& bank) {
	bank.getKredyt().setCzas(losujCzasKredytu());
	bank.getKredyt().setOprocentowanie(losujOprocentowanie());
	bank.getKredyt().setStawkaKary(losujStawkeKary(bank));
}
void Silnik::start() {
	srand(time(NULL));
	Wyswietlacz wyswietlacz;
	Kredyt kredytpeKO(0, 1, 2, 0);
	wsulica = std::make_shared<Ulica>();
	wspeKO = std::make_shared<Bank>("PeKO", 1, kredytpeKO);
	wsgielda = std::make_shared<DomMaklerski>();
	//wskasyno = std::make_shared<Kasyno>();
	lokacja = wsulica;
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
	this->gracz = Gracz(0, startowaKasa, nazwa, cel);
	losujOferteBanku(*wspeKO);
	glownaPetla();
}
void Silnik::glownaPetla() {
	if (!lokacja) lokacja = wsulica;
	while (true) {
		lokacja->wejdz(wyswietlacz, gracz, dni);
		std::cin >> wybor;
		switch (wybor) {
		case 1:
			lokacja = wsgielda;
			break;
		case 2:
			lokacja = wspeKO;
			break;
		case 3:
			//lokacja = wskasyno;
			break;
		case 4:
			przespijSie();
			lokacja = wsulica;
			break;
		default:
			lokacja = wsulica;
			break;
		}
		if (lokacja == wspeKO) {
			wBanku();
			lokacja = wsulica;
		}
		 else if (lokacja == wsgielda) {
			//wDomuMaklerskim();
			lokacja = wsulica;
		}
		 else if (lokacja == wskasyno) {
			//wKasynie();
			lokacja = wsulica;
		}
		 else if (lokacja == wsulica) {
		}
		 else {
			std::cout << "Nieznana lokacja. Wracam na ulicę." << std::endl;
			system("pause");
			lokacja = wsulica;
		}
	}
}
void Silnik::przespijSie() {
	dni++;
	wyswietlacz.przespijSie();
	losujOferteBanku(*wspeKO);
}
void Silnik::naUlicy() {
	wyswietlacz.glowneMenu(gracz, dni);
	std::cin >> wybor;
}
void Silnik::wBanku() {
	bool wyjscie = false;
	bool wKredycie = wspeKO->getCzyKredyt();
	long double kwota;
	while (!wyjscie) {
		wyswietlacz.wBanku();
		std::cin >> wybor;
		switch (wybor) {
		case 1:
			if (wKredycie) {
				std::cout << "Już masz kredyt! Nie możesz wziąć kolejnego." << std::endl;
				break;
			}
			wyswietlacz.warunkiKredytu(*wspeKO);
			std::cin >> wybor;
			if (wybor == 1) {
				wyswietlacz.branieKredytu();
				std::cin >> kwota;
				while (kwota < 0 || kwota > 100000) {
					wyswietlacz.zlaKwotaKredytu();
					std::cin >> kwota;
				}
				wspeKO->setCzyKredyt(true);
				wKredycie = true;
				gracz.setSrodki(gracz.getSrodki() + kwota);
				wspeKO->getKredyt().setWartosc(kwota);
				wyswietlacz.gratulacjeKredyt();
				break;
			}else if (wybor != 1) {
				break;
			}
		case 2:
			if (!wKredycie) {
				wyswietlacz.nieMaszKredytu();
				break;
			}
			wyswietlacz.splacanieKredytu(*wspeKO);
			std::cin >> kwota;
			if (kwota < 0 || kwota > wspeKO->getKredyt().getWartosc()) {
				wyswietlacz.zlaKwotaKredytu();
				break;
			}
			wspeKO->getKredyt().splac(kwota);
			wyswietlacz.infoSplacenie(*wspeKO, kwota);
			if (wspeKO->getKredyt().getWartosc() == 0) {
				wspeKO->setCzyKredyt(false);
				wKredycie = false;
				wyswietlacz.gratulacjeSplacenie();
			}
			break;
		case 3:
			wyswietlacz.rozejrzyjSieBank();
			break;
		case 4:
			wyjscie = true;
			break;
		default:
			wyswietlacz.niepoprawnyWybor();
			break;
		}
	}
}