#include "Silnik.h"
#include <vector>
#include <ctime>
#include <random>
#include <iostream>
#include <memory>
#include <stdlib.h>
#include "InterfejsWejscia.h"
#include "WejscieKonsolowe.h"

long double Silnik::losujWspolczynnikZmianyCeny() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_real_distribution<long double> dis(0.65, 1.45);
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
	//inicjalizacja firm
	Firma Pear("Pear", 17000000000000, 0.97, 15084294587, Akcje(1127, 1, 1127, 1127, 0, "PR", 1127));
	Firma Mikromiekki("Mikromiękki", 12000000000000, 3.33, 7389162561, Akcje(1624, 2, 1624, 1624, 0, "MKMK", 1624));
	Firma Googol("Googol", 17000000000000, 0.8, 12454212454, Akcje(1365, 3, 1365, 1365, 0, "GOOGL", 1365));
	Firma TrumpDonalds("TrumpDonalds", 720000000000, 6.75, 711462450, Akcje(1012, 4, 1012, 1012, 0, "TRPDLS", 1012));
	Firma Smasnung("Smasnung", 201500000000000, 34.31, 10515603799, Akcje(19162, 5, 19162, 19162, 0, "SMSG", 19162));
	wyswietlacz = std::make_shared<Wyswietlacz>();
	wejscie = std::make_shared<WejscieKonsolowe>();
	Kredyt kredytpeKO(0, 1, 2, 0);
	wsulica = std::make_shared<Ulica>();
	wspeKO = std::make_shared<Bank>("PeKO", 1, kredytpeKO);
	wsgielda = std::make_shared<DomMaklerski>();
	//wskasyno = std::make_shared<Kasyno>();
	lokacja = wsulica;
	short wybor;
	int startowaKasa = 0;
	wyswietlacz->ekranPowitalny();
	wyswietlacz->poczatekGry();
	wyswietlacz->uzueplnijDane1();
	std::string nazwa;
	nazwa = wejscie->pobierzString();
	wyswietlacz->uzueplnijDane2();
	long double cel;
	cel = wejscie->pobierzLongDouble();
	wyswietlacz->wybierzPoziomTrudnosci();
	wybor = wejscie->pobierzInt();
	switch(wybor) {
	case 1:
		startowaKasa = cel * 0.7;
		break;
	case 2:
		startowaKasa = cel * 0.4;
		break;
	case 3:
		startowaKasa = cel * 0.1;
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
		wybor = wejscie->pobierzInt();
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
			if (gracz.getKredytGracza().getCzas() == -1) {
				wspeKO->setCzyKredyt(false);
			}
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
	gracz.getKredytGracza().uplywDni();
	wspeKO->getKredyt().oprocentowanieDziennie();
	wspeKO->ponaglij(wyswietlacz, gracz);
	wspeKO->zbierzHaracz(gracz, wyswietlacz);
	wyswietlacz->przespijSie();
	losujOferteBanku(*wspeKO);
}
void Silnik::naUlicy() {
	wyswietlacz->glowneMenu(gracz, dni);
	std::cin >> wybor;
}
void Silnik::wBanku() {
	bool wyjscie = false;
	bool wKredycie = wspeKO->getCzyKredyt();
	long double kwota;
	while (!wyjscie) {
		wyswietlacz->wBanku();
		wybor = wejscie->pobierzInt();
		switch (wybor) {
		case 1:
			if (wKredycie) {
				std::cout << "Już masz kredyt! Nie możesz wziąć kolejnego." << std::endl;
				system("pause");
				break;
			}
			wyswietlacz->warunkiKredytu(*wspeKO);
			wybor = wejscie->pobierzInt();
			if (wybor == 1) {
				wyswietlacz->branieKredytu();
				kwota = wejscie->pobierzLongDouble();
				while (kwota < 0 || kwota > 100000) {
					wyswietlacz->zlaKwotaKredytu();
					kwota = wejscie->pobierzLongDouble();
				}
				wspeKO->setCzyKredyt(true);
				wKredycie = true;
				gracz.setSrodki(gracz.getSrodki() + kwota);
				gracz.setKredytGracza(Kredyt(kwota, wspeKO->getKredyt().getOprocentowanie(), wspeKO->getKredyt().getCzas(), wspeKO->getKredyt().getStawkaKary()));
				wyswietlacz->gratulacjeKredyt();
				break;
			}else if (wybor != 1) {
				break;
			}
		case 2:
			if (!wKredycie) {
				wyswietlacz->nieMaszKredytu();
				break;
			}
			wyswietlacz->splacanieKredytu(gracz);
			kwota = wejscie->pobierzLongDouble();
			if (kwota < 0 || kwota > gracz.getKredytGracza().getWartosc()) {
				wyswietlacz->zlaKwotaKredytu();
				break;
			}
			gracz.getKredytGracza().splac(kwota);
			wyswietlacz->infoSplacenie(gracz, kwota);
			if ( gracz.getKredytGracza().getWartosc() == 0) {
				wspeKO->setCzyKredyt(false);
				wKredycie = false;
				wyswietlacz->gratulacjeSplacenie();
			}
			break;
		case 3:
			wyswietlacz->rozejrzyjSieBank();
			break;
		case 4:
			wyjscie = true;
			break;
		default:
			wyswietlacz->niepoprawnyWybor();
			break;
		}
	}
}

void Silnik::wDomuMaklerskim() {
	wyswietlacz->uMaklera();
	bool wyjscie = false;
	int wybor;
	int ktore;
	while (!wyjscie) {
		wybor = wejscie->pobierzInt();
		switch (wybor) {
		case 1:
			wyswietlacz->sprawdzNotowania();
			wyswietlacz->spytajOKtore();
			ktore = wejscie->pobierzInt();
			break;
		case 2:
			wyswietlacz->zarzadzajAktywami(gracz);
			break;
		case 3:
			wyswietlacz->rozejrzyjSieMakler();
			break;
		default:
			wyswietlacz->niepoprawnyWybor();
			break;
		}
	}
}