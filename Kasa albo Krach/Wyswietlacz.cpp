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
    std::cout << gracz.getNazwaGracza() << std::endl;
    std::cout << "Kapitał: " << std::fixed << std::setprecision(10) << gracz.getKapital() << "\t\t\t\t\t Dzień: " << dni << std::endl;
    std::cout << "Środki: " << std::fixed << std::setprecision(10) << gracz.getSrodki() << std::endl;
    std::cout << "Co chcesz zrobić? " << std::endl;
    std::cout << "1 Idź do domu maklerskiego | 2 Idź do banku | 3 Idź do kasyna | 4 prześpij się (pomija dzień)" << std::endl;
}

void Wyswietlacz::otrzymanoDywidendy(long double calkowitaDywidenda) {
	std::cout << "Otrzymałeś dywidendy w wysokości: " << calkowitaDywidenda << std::endl;
    std::cout << "Gratulacje!" << std::endl;
	system("pause");
}

//------------------------------DOM MAKLERSKI---------------------------------------

void Wyswietlacz::uMaklera() {
    system("CLS");
    std::cout << "W domu maklerskim..." << std::endl;
    std::cout << "Co chcesz zrobić? " << std::endl;
    std::cout << "1 Sprawdź notowania | 2 Zarządzaj aktywami | 3 Rozejrzyj się | 4 Wyjdź" << std::endl;
}

void Wyswietlacz::sprawdzNotowania(const std::vector<Firma>& wszystkieFirmy) {
    std::cout << "Notowania:\n";

    for (size_t i = 0; i < wszystkieFirmy.size(); ++i) {
        Firma firma = wszystkieFirmy[i];
        std::cout << "\t" << i + 1 << ". " << firma.getAkcja().getSkrot() << "\n";
    }

    std::cout << std::endl; 
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

void Wyswietlacz::kosztyZycia(int jedzenie, int mieszkanie) {
	std::cout << "Koszty życia: " << std::endl;
	std::cout << "Jedzenie: " << jedzenie << std::endl;
	std::cout << "Mieszkanie: " << mieszkanie << std::endl;
	system("pause");
}
void Wyswietlacz::infoNotowanie(Firma& firma) {
    auto& akcja = firma.getAkcja();
    std::cout << std::endl;
    std::cout << firma.getNazwa() << " :" << std::endl;
    long double roznica2DniTemu = ((akcja.getCenaDwaDniPrzed() / akcja.getCenaTrzyDniPrzed()) - 1) * 100;
    long double roznica1DzienTemu = ((akcja.getCenaDzienPrzed() / akcja.getCenaDwaDniPrzed()) - 1) * 100;
    long double roznicaDzisiaj = ((akcja.getCena() / akcja.getCenaDzienPrzed()) - 1) * 100;
    std::cout << "2 dni temu: " << firma.getAkcja().getCenaDwaDniPrzed() << " Różnica: " << roznica2DniTemu << "%" << std::endl;
    std::cout << "1 dzień temu: " << firma.getAkcja().getCenaDzienPrzed() << " Różnica: " << roznica1DzienTemu << "%" << std::endl;
    std::cout << "Dzisiaj: " << firma.getAkcja().getCena() << " Różnica: "<< std::showpos <<  roznicaDzisiaj << std::noshowpos << "%" << std::endl;
	system("pause");
}

void Wyswietlacz::nieprawidloweDane() {
    std::cout << "Podano nieprawidłowe dane!" << std::endl;
    system("pause");
}

void Wyswietlacz::kupionoAkcje(Firma firma, long double ilosc){
    std::cout << "Kupiono " << ilosc << " akcji firmy " << firma.getNazwa() << std::endl;
	system("pause");
}

void Wyswietlacz::brakAkcjiNumer() {
	std::cout << "Nie masz akcji o podanym numerze!" << std::endl;
	system("pause");
}

void Wyswietlacz::brakTyleAkcji() {
	std::cout << "Nie masz tyle akcji!" << std::endl;
	system("pause");
}


void Wyswietlacz::nieMaszAkcji() {
    std::cout << "Nie posiadasz żadnych akcji :<" << std::endl;
    system("pause");
}

void Wyswietlacz::brakSrodkow() {
	std::cout << "Nie masz wystarczających środków!" << std::endl;
	system("pause");
}

void Wyswietlacz::akcjeSprzedane(long double ilosc) {
	std::cout << "Sprzedano " << ilosc << " akcji firmy "  << std::endl;
	system("pause");
}

void Wyswietlacz::usunietoAktywo() {
	std::cout << "Usunięto firmę z Twojego portfela akcji." << std::endl;
}

void Wyswietlacz::zarzadzajAktywami(Gracz& gracz) {
    if (gracz.getPosiadaneAkcje().empty()) {
        nieMaszAkcji();
    }
    else {
        std::cout << "Twoje aktywa: " << std::endl;
        for (int i = 0; i < gracz.getPosiadaneAkcje().size(); i++) {
            std::cout << i + 1 << ". " << gracz.getPosiadaneAkcje()[i].getSkrot() << std::endl;
        }
    }
    std::cout << "Co chcesz zrobić?" << std::endl;
    std::cout << "1 Kup aktywo | 2 Sprzedaj aktywo | 3 Rozejrzyj się | 4 Wyjdź" << std::endl;
}
void Wyswietlacz::sprawdzWalorGracza(Gracz& gracz, int ktore) {
    std::cout << "Informacje o posiadanym walorze: " << std::endl;
    std::cout << "Skrót: " << gracz.getPosiadaneAkcje()[ktore-1].getSkrot() << std::endl;
    std::cout << "Ilość: " << gracz.getPosiadaneAkcje()[ktore-1].getIlosc() << std::endl;
    std::cout << "Cena: " << gracz.getPosiadaneAkcje()[ktore-1].getCena() << std::endl;
	std::cout << "Wartość: " << gracz.getPosiadaneAkcje()[ktore - 1].getCena() * gracz.getPosiadaneAkcje()[ktore - 1].getIlosc() << std::endl;
}
void Wyswietlacz::Aktywo2(Gracz& gracz) {
    std::cout << "Ilość: " << std::endl;
}
void Wyswietlacz::Aktywo1(Gracz& gracz) {
    std::cout << "Ilość: " << std::endl;
}
void Wyswietlacz::sprzedajAktywo() {
	std::cout << "Ilość: " << std::endl;
}

void Wyswietlacz::rozejrzyjSieMakler() {
	system("CLS");
    std::cout << "Wygląda jak dom maklerski." << std::endl;
	system("pause");
}

//---------------------------------------BANK---------------------------------------

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
void Wyswietlacz::splacanieKredytu(Gracz& gracz) {
    system("CLS");
    std::cout << "Dni pozostałe do spłaty: " << gracz.getKredytGracza().getCzas() << std::endl;
	std::cout << "Do spłacenia pozostało: " << gracz.getKredytGracza().getWartosc() << std::endl;
    std::cout << "Ile chcesz spłacić?: " << std::endl;
}
void Wyswietlacz::gratulacjeSplacenie() {
    system("CLS");
    std::cout << "Gratulacje, Spłaciłeś kredyt! Ciesz się wolnością (na razie)" << std::endl;
    system("pause");
}
void Wyswietlacz::infoSplacenie(Gracz& gracz, long double kwota) {
    system("CLS");
    std::cout << "Spłaciłeś " << kwota << std::endl;
    std::cout << ". Pozostało do spłaty: " << gracz.getKredytGracza().getWartosc() << std::endl;
	system("pause");
}
void Wyswietlacz::rozejrzyjSieBank() {
    system("CLS");
    std::cout << "Wygląda jak bank." << std::endl;
	system("pause");
}

void Wyswietlacz::ponaglenie10Dni() {
    system("cls");
	std::cout << "Do spłacenia kredytu pozostało 10 dni! Spiesz się!" << std::endl;
    system("pause");
}
void Wyswietlacz::ponaglenie5Dni() {
    system("cls");
	std::cout << "Do spłacenia kredytu pozostało 5 dni! Spiesz się!" << std::endl;
    system("pause");
}
void Wyswietlacz::ponaglenie1Dzien() {
    system("cls");
	std::cout << "Do spłacenia kredytu pozostało 1 dzień! Spiesz się!" << std::endl;
    system("pause");
}
void Wyswietlacz::infoKwotaKredyt(Gracz& gracz) {
	system("cls");
	std::cout << "Do spłacenia pozostało: " << std::fixed << std::setprecision(2) << gracz.getKredytGracza().getWartosc() << std::endl;
	system("pause");
}


void Wyswietlacz::grozaKredytowa(Gracz& gracz) {
	system("cls");
	std::cout << "Nie spłaciłeś kredytu na czas! Czas wyciągnąć konsekwencje..." << std::endl;
	system("pause");
	std::cout << "Kara za nieterminową spłatę: " << std::fixed << std::setprecision(2) << gracz.getKredytGracza().getStawkaKary() * 100 << "%" << std::endl;
	system("pause");
	std::cout << "Zostało do spłaty: " << gracz.getKredytGracza().getWartosc() << std::endl;
	system("pause");
	std::cout << "Łącznie wychodzi: " << std::fixed << std::setprecision(2) << gracz.getKredytGracza().getWartosc() * (1.0L + gracz.getKredytGracza().getStawkaKary()) << std::endl;
	system("pause");
	std::cout << "Bank peKO pozdrawia i życzy sukcesów inwestycyjnych w przyszłości!" << std::endl;
	system("pause");
}

//------------------------------KASYNO---------------------------------------

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
