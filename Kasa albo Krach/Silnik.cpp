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
	std::uniform_real_distribution<long double> dis(0.9, 1.15);
	return dis(gen);
}

void Silnik::losujCenyAkcji(std::shared_ptr<std::vector<Firma>> firma, long double q) {
	for (int i = 0; i < firma->size(); i++) {
		long double p = losujWspolczynnikZmianyCeny();
		long double a = firma->at(i).getAkcja().getCena() * p * q;
		firma->at(i).getAkcja().setCenaTrzyDniPrzed(firma->at(i).getAkcja().getCenaDwaDniPrzed());
		firma->at(i).getAkcja().setCenaDwaDniPrzed(firma->at(i).getAkcja().getCenaDzienPrzed());
		firma->at(i).getAkcja().setCenaDzienPrzed(firma->at(i).getAkcja().getCena());
		firma->at(i).getAkcja().setCena(a);
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

void Silnik::pobierzKosztyZycia(Gracz& gracz) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> jedzenied(10, 30);
	std::uniform_int_distribution<int> mieszkanied(20, 50);
	int jedzenie = jedzenied(gen);
	int mieszkanie = mieszkanied(gen);
	wyswietlacz->kosztyZycia(jedzenie, mieszkanie);
	gracz.setSrodki(gracz.getSrodki() - (jedzenie + mieszkanie));
}

void Silnik::liczKapital(Gracz& gracz) {
	long double kapital = gracz.getSrodki();
	for (size_t i = 0; i < gracz.getPosiadaneAkcje().size(); ++i) {
		Akcje& akcja = gracz.getPosiadaneAkcje()[i];
		kapital += akcja.getIlosc() * akcja.getCena();
	}
	gracz.setKapital(kapital);
}

void Silnik::aktualizujCenyWPortfelu(Gracz& gracz, const std::vector<Firma>& wszystkieFirmy) {
	std::vector<Akcje>& portfel = gracz.getPosiadaneAkcje();

	for (size_t i = 0; i < portfel.size(); ++i) {

		for (size_t j = 0; j < wszystkieFirmy.size(); ++j) {

			if (portfel[i].getSkrot() == wszystkieFirmy[j].getAkcja().getSkrot()) {

				Akcje aktualneDaneFirmy = wszystkieFirmy[j].getAkcja();

				portfel[i].setCena(aktualneDaneFirmy.getCena());
				portfel[i].setCenaDzienPrzed(aktualneDaneFirmy.getCenaDzienPrzed());
				portfel[i].setCenaDwaDniPrzed(aktualneDaneFirmy.getCenaDwaDniPrzed());
				portfel[i].setCenaTrzyDniPrzed(aktualneDaneFirmy.getCenaTrzyDniPrzed());
				break;
			}
		}
	}
}

void Silnik::wyplacDywidendy(Gracz& gracz, std::vector<Firma>& wszystkieFirmy) {
	std::vector<Akcje>& portfel = gracz.getPosiadaneAkcje();
	long double calkowitaDywidenda = 0;

	for (size_t i = 0; i < portfel.size(); ++i) {

		for (size_t j = 0; j < wszystkieFirmy.size(); ++j) {
			if (portfel[i].getSkrot() == wszystkieFirmy[j].getAkcja().getSkrot()) {

				long double zyskZFirmy = portfel[i].getIlosc() * wszystkieFirmy[j].getDywidendy();
				calkowitaDywidenda += zyskZFirmy;

				break;
			}
		}
	}

	if (calkowitaDywidenda > 0) {
		gracz.setSrodki(gracz.getSrodki() + calkowitaDywidenda);

		wyswietlacz->otrzymanoDywidendy(calkowitaDywidenda);
	}
}

void Silnik::start() {
	//inicjalizacja firm
	Firma Pear("Pear", 17000000000000, 0.97, 15084294587, Akcje(1127, 1, 1127, 1127, 0, "PR", 1127));
	Firma Mikromiekki("Mikromiękki", 12000000000000, 3.33, 7389162561, Akcje(1624, 2, 1624, 1624, 0, "MKMK", 1624));
	Firma Googol("Googol", 17000000000000, 0.8, 12454212454, Akcje(1365, 3, 1365, 1365, 0, "GOOGL", 1365));
	Firma TrumpDonalds("TrumpDonalds", 720000000000, 6.75, 711462450, Akcje(1012, 4, 1012, 1012, 0, "TRPDLS", 1012));
	Firma Smasnung("Smasnung", 201500000000000, 34.31, 10515603799, Akcje(19162, 5, 19162, 19162, 0, "SMSG", 19162));
	Firma UniwersytetLodzki("Uniwersytet Łódzki", 1000000000, 10, 10000000, Akcje(100, 6, 100, 100, 0, "UL", 100));
	Firma KukaKula("Kuka-Kula", 1000000000000, 1.93, 3424657534, Akcje(292, 7, 292, 292, 0, "KKL", 292));
	Firma Poopsi("Poopsi", 706000000000, 5.38, 1368217054, Akcje(516, 8, 516, 516, 0, "PPSI", 516));
	Firma Wiza("Wiza", 2000000000000, 2.42, 1699235344, Akcje(1177, 9, 1177, 1177, 0, "WZA", 1177));
	Firma PlacKolezka("Płać Koleżka", 132000000000, 0.51, 874172185, Akcje(151, 10, 151, 151, 0, "PPL", 151));
	Firma Mersidis("Mersidis", 196000000000, 5, 960784313, Akcje(204, 11, 204, 204, 0, "MRCDS", 204));
	Firma PietraIndustries("Piętra Industries", 1000000000000, 6.07, 89371283, Akcje(670, 12, 670, 670, 0, "PIĘTRA", 670));
	firmy->push_back(Pear);
	firmy->push_back(Mikromiekki);
	firmy->push_back(Googol);
	firmy->push_back(TrumpDonalds);
	firmy->push_back(Smasnung);
	firmy->push_back(UniwersytetLodzki);
	firmy->push_back(KukaKula);
	firmy->push_back(Poopsi);
	firmy->push_back(Wiza);
	firmy->push_back(PlacKolezka);
	firmy->push_back(Mersidis);
	firmy->push_back(PietraIndustries);
	wyswietlacz = std::make_shared<Wyswietlacz>();
	wejscie = std::make_shared<WejscieKonsolowe>();
	Kredyt kredytpeKO(0, 1, 2, 0);
	wsulica = std::make_shared<Ulica>();
	wspeKO = std::make_shared<Bank>("PeKO", 1, kredytpeKO);
	wsgielda = std::make_shared<DomMaklerski>();
	//wskasyno = std::make_shared<Kasyno>();
	lokacja = wsulica;
	int wybor;
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
		liczKapital(gracz);
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
			wDomuMaklerskim();
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
	losujCenyAkcji(firmy, 1);
	aktualizujCenyWPortfelu(gracz, *firmy);
	if (dni % 11 == 0) {
		wyplacDywidendy(gracz, *firmy);
	}
}
void Silnik::naUlicy() {
	wyswietlacz->glowneMenu(gracz, dni);
	wybor = wejscie->pobierzInt();
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
	bool wyjscie = false;
	int wybor;
	int ktore;
	long double ilosc;
	Firma* temp;
	while (!wyjscie) {
		wyswietlacz->uMaklera();
		wybor = wejscie->pobierzInt();
		switch (wybor) {
		case 1:
			wyswietlacz->sprawdzNotowania(*firmy);
			wyswietlacz->spytajOKtore();
			ktore = wejscie->pobierzInt();
			temp = &(*firmy)[ktore - 1];
			wyswietlacz->infoNotowanie(*temp);
			break;
		case 2:
			wyswietlacz->zarzadzajAktywami(gracz);
			wybor = wejscie->pobierzInt();
			if (wybor == 1) {
				wyswietlacz->sprawdzNotowania(*firmy);
				wyswietlacz->spytajOKtore();
				ktore = wejscie->pobierzInt();
				temp = &(*firmy)[ktore - 1];
				wyswietlacz->infoNotowanie(*temp);
				wyswietlacz->spytajOIlosc();
				ilosc = wejscie->pobierzLongDouble();
				wsgielda->KupAkcje(gracz, *temp, ilosc, wyswietlacz);
			}
			else if (wybor == 2) {
				if (gracz.getPosiadaneAkcje().empty()) {
					wyswietlacz->nieMaszAkcji();
					break;
				}
				else {
					wyswietlacz->spytajOKtore();
					ktore = wejscie->pobierzInt();
					if (ktore <= 0 || ktore > gracz.getPosiadaneAkcje().size()) {
						wyswietlacz->brakAkcjiNumer();
						break;
					}
					else {
						temp = &(*firmy)[ktore - 1];
						wyswietlacz->sprawdzWalorGracza(gracz, ktore);
						wyswietlacz->sprzedajAktywo();
						ilosc = wejscie->pobierzLongDouble();
						wsgielda->sprzedajAkcje(gracz, ktore, ilosc, wyswietlacz);
					}
				}
			}
			break;
		case 3:
			wyswietlacz->rozejrzyjSieMakler();
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