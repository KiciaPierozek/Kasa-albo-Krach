//
// Created by Admin on 22.04.2026.
//
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Wyswietlacz.h"
#include "Gracz.h"
#include "Silnik.h"
#include "Firma.h"
void Wyswietlacz::ekranPowitalny() {
    std::cout << R"(
$$\   $$\                                              $$\ $$\                       $$\   $$\                              $$\
$$ | $$  |                                             $$ |$$ |                      $$ | $$  |                             $$ |
$$ |$$  / $$$$$$\   $$$$$$$\  $$$$$$\         $$$$$$\  $$ |$$$$$$$\   $$$$$$\        $$ |$$  /  $$$$$$\  $$$$$$\   $$$$$$$\ $$$$$$$\
$$$$$  /  \____$$\ $$  _____| \____$$\        \____$$\ $$ |$$  __$$\ $$  __$$\       $$$$$  /  $$  __$$\ \____$$\ $$  _____|$$  __$$\
$$  $$<   $$$$$$$ |\$$$$$$\   $$$$$$$ |       $$$$$$$ |$$ |$$ |  $$ |$$ /  $$ |      $$  $$<   $$ |  \__|$$$$$$$ |$$ /      $$ |  $$ |
$$ |\$$\ $$  __$$ | \____$$\ $$  __$$ |      $$  __$$ |$$ |$$ |  $$ |$$ |  $$ |      $$ |\$$\  $$ |     $$  __$$ |$$ |      $$ |  $$ |
$$ | \$$\\$$$$$$$ |$$$$$$$  |\$$$$$$$ |      \$$$$$$$ |$$ |$$$$$$$  |\$$$$$$  |      $$ | \$$\ $$ |     \$$$$$$$ |\$$$$$$$\ $$ |  $$ |
\__|  \__|\_______|\_______/  \_______|       \_______|\__|\_______/  \______/       \__|  \__|\__|      \_______| \_______|\__|  \__|






Piotr Mleczko 2026                                                                                                                         




)" << std::endl;
}

void Wyswietlacz::poczatekGry() {
    std::cout << "Nacisnij przycisk aby zagrać" << std::endl;
    system("pause");
    system("CLS");
}
void Wyswietlacz::uzueplnijDane1() {
    std::cout << "Podaj nazwę gracza: " << std::endl;
}
void Wyswietlacz::uzueplnijDane2() {
    system("CLS");
    std::cout << "Podaj cel (kwotę, którą chcesz osiągnąć): " << std::endl;
}
void Wyswietlacz::wybierzPoziomTrudnosci() {
    system("CLS");
    std::cout << "Wybierz poziom trudności: " << std::endl;
	std::cout << "1 Łatwy | 2 Średni | 3 Trudny" << std::endl;
}
void Wyswietlacz::glowneMenu(Gracz& gracz, int dni) {
    system("CLS");
    std::cout << "Kapitał: " << gracz.getKapital() << "\t\t\t\t\t Dzień: " << dni << std::endl;
    std::cout << "Środki: " << gracz.getSrodki() << std::endl;
    std::cout << "Co chcesz zrobić? " << std::endl;
    std::cout << "1 Idź do domu maklerskiego | 2 Idź do banku | 3 Idź do kasyna | 4 prześpij się (pomija dzień)" << std::endl;
}

void Wyswietlacz::uMaklera() {
    system("CLS");
    std::cout << "W domu maklerskim..." << std::endl;
    std::cout << "Co chcesz zrobić? " << std::endl;
    std::cout << "1 Sprawdź notowania | 2 Zarządzaj aktywami | 3 Rozejrzyj się | 4 Wyjdź" << std::endl;
}

void Wyswietlacz::sprawdzNotowania() {
    std::cout << "Notowania: " << std::endl;
    std::cout << "\t 1.  PAR" << std::endl;
    std::cout << "\t 2.  MKMK" << std::endl;
    std::cout << "\t 3.  GOGL" << std::endl;
    std::cout << "\t 4.  TRDM" << std::endl;
    std::cout << "\t 5.  KBC" << std::endl;
    std::cout << "\t 6.  SMSG" << std::endl;
    std::cout << "\t 7.  UŁ" << std::endl;
    std::cout << "\t 8.  KUKA" << std::endl;
    std::cout << "\t 9.  PPSI" << std::endl;
    std::cout << "\t 10. WZA" << std::endl;
    std::cout << "\t 11. PCKA" << std::endl;
    std::cout << "\t 12. MRSD" << std::endl;
}
void Wyswietlacz::spytajOKtore() {
    std::cout << "Której spółki? (Podaj numer)" << std::endl;
}
void Wyswietlacz::spytajOIlosc() {
	std::cout << "Ile? : " << std::endl;
}
void Wyswietlacz::niepoprawnyWybor() {
    std::cout << "Niepoprawny wybór -w-." << std::endl;
}
void Wyswietlacz::przespijSie() {
	system("CLS");
    std::cout << "Przespałeś się i minął kolejny dzień." << std::endl;
	system("pause");
}
void Wyswietlacz::infoNotowanie(Firma& firma, long double cenaTrzyDni) {
    std::cout << firma.getNazwa() << " :" << std::endl;
    std::cout << "2 dni temu: " << firma.getAkcja().getCenaDwaDniPrzed() << " Różnica: " << ((firma.getAkcja().getCenaDwaDniPrzed()/cenaTrzyDni)-1)*100 << "%" << std::endl;
    std::cout << "1 dzień temu: " << firma.getAkcja().getCenaDzienPrzed() << " Różnica: " << ((firma.getAkcja().getCenaDzienPrzed()/firma.getAkcja().getCenaDzienPrzed())-1)*100 << "%" << std::endl;
    std::cout << "Dzisiaj: " << firma.getAkcja().getCena() << " Różnica: "<< std::showpos <<  ((firma.getAkcja().getCena()/firma.getAkcja().getCenaDzienPrzed())-1)*100 << std::noshowpos << "%" << std::endl;
}

void Wyswietlacz::zarzadzajAktywami(Gracz& gracz) {
	for (int i = 0; i < gracz.getPosiadaneAkcje().size(); i++) {
		std::cout << gracz.getPosiadaneAkcje()[i].getSkrot() << ": " << gracz.getPosiadaneAkcje()[i].getIlosc() << " szt. Cena: " << gracz.getPosiadaneAkcje()[i].getCena() * gracz.getPosiadaneAkcje()[i].getIlosc() << std::endl;
    }
    std::cout << "Co chcesz zrobić?" << std::endl;
    std::cout << "1 Kup aktywo | 2 Sprzedaj aktywo | 3 Rozejrzyj się | 4 Wyjdź" << std::endl;
}
void Wyswietlacz::Aktywo2(Gracz& gracz) {
    std::cout << "Ilość: " << std::endl;
}

void Wyswietlacz::sprzedajAktywo(Gracz& gracz) {
	std::cout << "Ilość: " << std::endl;
}

void Wyswietlacz::rozejrzyjSieMakler() {
	system("CLS");
    std::cout << "Wygląda jak dom maklerski." << std::endl;
	system("pause");
}

void Wyswietlacz::wBanku() {
    system("CLS");
	std::cout << "Wszedłeś do banku. Co chcesz zrobić?" << std::endl;
    std::cout << "1 Weź kredyt | 2 Spłać zaczęrpnięty kredyt | 3 Rozejrzyj się | 4 Wyjdź" << std::endl;
}

void Wyswietlacz::warunkiKredytu(Bank& bank) {
    system("CLS");
    std::cout << "Bank oferuje następujące warunki kredytu: " << std::endl;
	std::cout << "Oprocentowanie: " << std::fixed << std::setprecision(2) << bank.getKredyt().getOprocentowanie() * 100 << "%" << std::endl;
	std::cout << "Czas trwania: " << bank.getKredyt().getCzas() << " dni" << std::endl;
	std::cout << "Stawka kary za nieterminową spłatę: " << bank.getKredyt().getStawkaKary() * 100 << "%" << std::endl;
	std::cout << "1 Przystań na te warunki i weź kredyt | 2 Odrzuć ofertę" << std::endl;
}
void Wyswietlacz::odrzucKredyt() {
    system("CLS");
    std::cout << "Odrzuciłeś ofertę kredytu." << std::endl;
}
void Wyswietlacz::branieKredytu() {
    std::cout << "Na jaką kwotę (maksymalnie do 100 tys): " << std::endl;
}
void Wyswietlacz::zlaKwotaKredytu() {
    std::cout << "Niepoprawna kwota." << std::endl;
    std::cout << "Spróbuj jeszcze raz" << std::endl;
}
void Wyswietlacz::nieMaszKredytu() {
    std::cout << "Nie masz kredytu do spłacenia!" << std::endl;
	system("pause");
}
void Wyswietlacz::gratulacjeKredyt() {
    std::cout << "Gratulacje! Wziąłeś kredyt!" << std::endl;
	system("pause");
}
void Wyswietlacz::splacanieKredytu(Bank& bank) {
    system("CLS");
    std::cout << "Dni pozostałe do spłaty: " << bank.getKredyt().getCzas() << std::endl;
	std::cout << "Do spłacenia pozostało: " << bank.getKredyt().getWartosc() << std::endl;
    std::cout << "Ile chcesz spłacić?: " << std::endl;
}
void Wyswietlacz::gratulacjeSplacenie() {
    system("CLS");
    std::cout << "Gratulacje, Spłaciłeś kredyt! Ciesz się wolnością (na razie)" << std::endl;
    system("pause");
}
void Wyswietlacz::infoSplacenie(Bank& bank, long double kwota) {
    system("CLS");
    std::cout << "Spłaciłeś " << kwota << std::endl;
    std::cout << ". Pozostało do spłaty: " << bank.getKredyt().getWartosc() << std::endl;
	system("pause");
}
void Wyswietlacz::rozejrzyjSieBank() {
    system("CLS");
    std::cout << "Wygląda jak bank." << std::endl;
	system("pause");
}



void Wyswietlacz::wKasynie() {
    system("CLS");
	std::cout << "Wszedłeś do kasyna. Co chcesz zrobić?" << std::endl;
	std::cout << "1 Zagraj w grę | 2 Rozejrzyj się | 3 Wyjdź" << std::endl;
}

void Wyswietlacz::wyborGry() {
    system("CLS");
    std::cout << "Jaką?:" << std::endl;
	std::cout << "1 BlackJack | 2 Ruletka | 3 Jednak nie" << std::endl;
}

void Wyswietlacz::stawka() {
    std::cout << "Podaj stawkę:" << std::endl;
}

void Wyswietlacz::blackJack() {
    //do implementacji!!!
}
void Wyswietlacz::obstaw() {
    system("CLS");
    std::cout << "A więc ruletka..." << std::endl;
	std::cout << "Na co chcesz postawić?" << std::endl;
	std::cout << R"(
Podaj numer(0-36) aby obstawić numer. Wygrana 35:1.
Wpisz 37 aby obstawić liczby parzyste. Wygrana 1:1.
Wpisz 38 aby obstawić liczby nieparzyste. Wygrana 1:1
Wpisz 39 aby obstawić czarne. Wygrana 1:1.
Wpisz 40 aby obstawić czerwone: Wygrana 1:1.
)";
}
void Wyswietlacz::ruletka() {
	//Do implementacji!!!
}

void Wyswietlacz::kasynoWygrana(long double wygrana) {
    system("CLS");
	std::cout << "Gratulacje! Wygrałeś " << wygrana << std::endl;
	system("pause");
}

void Wyswietlacz::kasynoPrzegrana() {
    system("CLS");
    std::cout << "Przegrałeś :<" << std::endl;
	system("pause");
}

void Wyswietlacz::rozejrzyjSieKasyno() {
    system("CLS");
	std::cout << "Wygląda jak kasyno." << std::endl;
	system("pause");
}
