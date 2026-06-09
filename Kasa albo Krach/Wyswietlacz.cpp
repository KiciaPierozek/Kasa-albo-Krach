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
    system("pause >nul");
    system("CLS");
}
void Wyswietlacz::uzueplnijDane1() {
    std::cout << "Podaj imię: " << std::endl;
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

    std::cout << "Kapitał: " << std::fixed << std::setprecision(2) << gracz.getKapital() << "\t\t\t\t\t Dzień: " << dni << std::endl;

    std::cout << "Środki: " << std::fixed << std::setprecision(2) << gracz.getSrodki() << " " << "\t\t\t\t\tCel: " << gracz.getCel() << std::endl;

    std::cout << "Co chcesz zrobić? " << std::endl;

    std::cout << "1 Idź do domu maklerskiego | 2 Idź do banku | 3 Idź do kasyna | 4 Prześpij się (pomija dzień)" << std::endl;

}

void Wyswietlacz::otrzymanoDywidendy(long double calkowitaDywidenda) {
	std::cout << "Otrzymałeś dywidendy w wysokości: " << calkowitaDywidenda << std::endl;
    std::cout << "Gratulacje!" << std::endl;
	system("pause >nul");
}

//------------------------------DOM MAKLERSKI---------------------------------------

void Wyswietlacz::uMaklera() {
    system("CLS");
    std::cout << "W domu maklerskim..." << std::endl;
    std::cout << "Co chcesz zrobić? " << std::endl;
    std::cout << "1 Sprawdź notowania | 2 Zarządzaj aktywami | 3 Rozejrzyj się | 4 Wyjdź" << std::endl;
}

void Wyswietlacz::sprawdzNotowania1(const std::vector<Firma>& wszystkieFirmy) {
    std::cout << "Notowania:\n";
    int licznik = 1;
    for (size_t i = 0; i < wszystkieFirmy.size(); ++i) {
        Firma firma = wszystkieFirmy[i];
        std::cout << "\t" << i + 1 << ". " << firma.getAkcja().getSkrot() << "\n";
        licznik++;
    }
	std::cout << "\t" << licznik << ". Wyświetl notowania z ostatniego dnia\n";
    std::cout << std::endl; 
}
void Wyswietlacz::sprawdzNotowania2(const std::vector<Firma>& wszystkieFirmy) {
    std::cout << "Notowania:\n";
    int licznik = 1;
    for (size_t i = 0; i < wszystkieFirmy.size(); ++i) {
        Firma firma = wszystkieFirmy[i];
        std::cout << "\t" << i + 1 << ". " << firma.getAkcja().getSkrot() << "\n";
        licznik++;
    }
}
void Wyswietlacz::wyswietlOstatniDzien(std::vector<Firma>& wszystkieFirmy) {
    system("CLS");
    std::cout << "=========================================================================\n";
    std::cout << "                      AKTUALNE NOTOWANIA GIEŁDOWE                        \n";
    std::cout << "=========================================================================\n";

    std::cout << std::left << std::setw(25) << "Nazwa firmy"
        << std::setw(12) << "Skrot"
        << "Aktualna cena akcji" << "\n";
    std::cout << "-------------------------------------------------------------------------\n";

    for (size_t i = 0; i < wszystkieFirmy.size(); ++i) {
        Firma& firma = wszystkieFirmy[i];

        std::cout << std::left << std::setw(25) << firma.getNazwa()
            << std::setw(12) << firma.getAkcja().getSkrot()
            << std::fixed << std::setprecision(2) << firma.getAkcja().getCena() << "\n";
    }

    std::cout << "=========================================================================\n";
    system("pause >nul");
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
	system("pause >nul");
}

void Wyswietlacz::kosztyZycia(int jedzenie, int mieszkanie) {
	std::cout << "Koszty życia: " << std::endl;
	std::cout << "Jedzenie: " << jedzenie << std::endl;
	std::cout << "Mieszkanie: " << mieszkanie << std::endl;
	system("pause >nul");
}
void Wyswietlacz::infoNotowanie(Firma& firma) {
    auto& akcja = firma.getAkcja();
    std::cout << std::endl;
    std::cout << firma.getNazwa() << " :" << std::endl;
    long double roznica2DniTemu = ((akcja.getCenaDwaDniPrzed() / akcja.getCenaTrzyDniPrzed()) - 1) * 100;
    long double roznica1DzienTemu = ((akcja.getCenaDzienPrzed() / akcja.getCenaDwaDniPrzed()) - 1) * 100;
    long double roznicaDzisiaj = ((akcja.getCena() / akcja.getCenaDzienPrzed()) - 1) * 100;
    std::cout << "2 dni temu: " << firma.getAkcja().getCenaDwaDniPrzed() << " Różnica: " << std::showpos << roznica2DniTemu << "%" << std::endl;
    std::cout << "1 dzień temu: " << firma.getAkcja().getCenaDzienPrzed() << " Różnica: " << std::showpos << roznica1DzienTemu << "%" << std::endl;
    std::cout << "Dzisiaj: " << firma.getAkcja().getCena() << " Różnica: "<< std::showpos <<  roznicaDzisiaj << std::noshowpos << "%" << std::endl;
	system("pause >nul");
}

void Wyswietlacz::nieprawidloweDane() {
    std::cout << "Podano nieprawidłowe dane!" << std::endl;
    system("pause >nul");
}

void Wyswietlacz::kupionoAkcje(Firma firma, long double ilosc){
    std::cout << "Kupiono " << ilosc << " akcji firmy " << firma.getNazwa() << std::endl;
	system("pause >nul");
}

void Wyswietlacz::brakAkcjiNumer() {
	std::cout << "Nie masz akcji o podanym numerze!" << std::endl;
	system("pause >nul");
}

void Wyswietlacz::brakTyleAkcji() {
	std::cout << "Nie masz tyle akcji!" << std::endl;
	system("pause >nul");
}


void Wyswietlacz::nieMaszAkcji() {
    std::cout << "Nie posiadasz żadnych akcji :<" << std::endl;
    system("pause >nul");
}

void Wyswietlacz::brakSrodkow() {
	std::cout << "Nie masz wystarczających środków!" << std::endl;
	system("pause >nul");
}

void Wyswietlacz::akcjeSprzedane(long double ilosc) {
	std::cout << "Sprzedano " << ilosc << " akcji firmy "  << std::endl;
	system("pause >nul");
}

void Wyswietlacz::usunietoAktywo() {
	std::cout << "Usunięto firmę z Twojego portfela akcji." << std::endl;
	system("pause >nul");
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
    std::cout << "1 Kup aktywo | 2 Sprzedaj aktywo" << std::endl;
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
	system("pause >nul");
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
void Wyswietlacz::maszKredyt() {
    std::cout << "Już masz kredyt! Nie możesz wziąć kolejnego." << std::endl;
    system("pause >nul");
}
void Wyswietlacz::nieMaszKredytu() {
    std::cout << "Nie masz kredytu do spłacenia!" << std::endl;
	system("pause >nul");
}
void Wyswietlacz::gratulacjeKredyt() {
    std::cout << "Gratulacje! Wziąłeś kredyt!" << std::endl;
	system("pause >nul");
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
    system("pause >nul");
}
void Wyswietlacz::infoSplacenie(Gracz& gracz, long double kwota) {
    system("CLS");
    std::cout << "Spłaciłeś " << kwota << std::endl;
    std::cout << "Pozostało do spłaty: " << gracz.getKredytGracza().getWartosc() << std::endl;
	system("pause >nul");
}
void Wyswietlacz::rozejrzyjSieBank() {
    system("CLS");
    std::cout << "Wygląda jak bank." << std::endl;
	system("pause >nul");
}

void Wyswietlacz::ponaglenie10Dni() {
    system("cls");
	std::cout << "Do spłacenia kredytu pozostało 10 dni! Spiesz się!" << std::endl;
    system("pause >nul");
}
void Wyswietlacz::ponaglenie5Dni() {
    system("cls");
	std::cout << "Do spłacenia kredytu pozostało 5 dni! Spiesz się!" << std::endl;
    system("pause >nul");
}
void Wyswietlacz::ponaglenie1Dzien() {
    system("cls");
	std::cout << "Do spłacenia kredytu pozostało 1 dzień! Spiesz się!" << std::endl;
    system("pause >nul");
}
void Wyswietlacz::infoKwotaKredyt(Gracz& gracz) {
	system("cls");
	std::cout << "Do spłacenia pozostało: " << std::fixed << std::setprecision(2) << gracz.getKredytGracza().getWartosc() << std::endl;
	system("pause >nul");
}


void Wyswietlacz::grozaKredytowa(Gracz& gracz) {
	system("cls");
	std::cout << "Nie spłaciłeś kredytu na czas! Czas wyciągnąć konsekwencje..." << std::endl;
	system("pause >nul");
	std::cout << "Kara za nieterminową spłatę: " << std::fixed << std::setprecision(2) << gracz.getKredytGracza().getStawkaKary() * 100 << "%" << std::endl;
	system("pause >nul");
	std::cout << "Zostało do spłaty: " << gracz.getKredytGracza().getWartosc() << std::endl;
	system("pause >nul");
	std::cout << "Łącznie wychodzi: " << std::fixed << std::setprecision(2) << gracz.getKredytGracza().getWartosc() * (1.0L + gracz.getKredytGracza().getStawkaKary()) << std::endl;
	system("pause >nul");
	std::cout << "Bank peKO pozdrawia i życzy sukcesów inwestycyjnych w przyszłości!" << std::endl;
	system("pause >nul");
}

//------------------------------KASYNO---------------------------------------

void Wyswietlacz::wKasynie() {
    system("CLS");
	std::cout << "Wszedłeś do kasyna. Co chcesz zrobić?" << std::endl;
	std::cout << "1 Zagraj w grę | 2 Rozejrzyj się | 3 Wyjdź" << std::endl;
}

void Wyswietlacz::wyborGry() {
    system("CLS");
    std::cout << "Którą grę wybierasz?:" << std::endl;
	std::cout << "1 BlackJack | 2 Ruletka | 3 Jednak nie" << std::endl;
}

void Wyswietlacz::stawka() {
    std::cout << "Podaj stawkę:" << std::endl;
}


void Wyswietlacz::pokazStanGryBlackjack(const std::string& kartyKrupiera, const std::string& kartyGracza, int punktyGracza) {
        system("CLS");
        std::cout << "--- BLACKJACK ---\n";
        std::cout << "Krupier: " << kartyKrupiera << "\n";
        std::cout << "Ty: " << kartyGracza << " (" << punktyGracza << " pkt)\n\n";
}
void Wyswietlacz::pokazWynikBlackjack(const std::string& kartyKrupiera, int pktKrupiera, const std::string& kartyGracza, int pktGracza, int rezultat) {
    std::cout << "\n--- WYNIKI KOŃCOWE ---\n";
    std::cout << "Krupier: " << kartyKrupiera << " (" << pktKrupiera << " pkt)\n";
    std::cout << "Ty: " << kartyGracza << " (" << pktGracza << " pkt)\n\n";

    if (rezultat == 1) std::cout << "Wygrywasz!\n";
    else if (rezultat == 2) std::cout << "Krupier wygrywa!\n";
    else std::cout << "Remis!\n";
}
void Wyswietlacz::nieMaszSrodkow() {
	std::cout << "Nie masz wystarczajacych środków na grę!" << std::endl;
}
void Wyswietlacz::podajLiczbe() {
	std::cout << "Podaj liczbę (0-36): " << std::endl;
}
void Wyswietlacz::nieMaLiczby() {
    std::cout << "Nie ma takiej liczby na kole! Podaj od 0 do 36: " << std::endl;
}
void Wyswietlacz::czerwonyCzarny() {
    std::cout << "1 - Czerwony | 2 - Czarny: " << std::endl;
}
void Wyswietlacz::parzysteNieparzyste() {
	std::cout << "1 - Parzyste | 2 - Nieparzyste: " << std::endl;
}
void Wyswietlacz::wybierzJD() {
    std::cout << "Wybierz 1 lub 2: " << std::endl;
}
void Wyswietlacz::nieprawidlowyWyborKasyno() {
    std::cout << "Nieprawidłowy wybór! Pieniądze wracają na konto.\n";
	system("pause >nul");
}
void Wyswietlacz::fura() {
    std::cout << "Fura! Przekraczasz 21 punktów" << std::endl;
}
void Wyswietlacz::wybierzKarte() {
    std::cout << "1 - Dobierz karte | 2 - Spasuj" << std::endl;
}

void Wyswietlacz::kasynoWygrana(long double wygrana) {
    system("CLS");
	std::cout << "Gratulacje! Wygrałeś " << wygrana << std::endl;
	system("pause >nul");
}

void Wyswietlacz::kasynoPrzegrana() {
    system("CLS");
    std::cout << "Przegrałeś :<" << std::endl;
	system("pause >nul");
}

void Wyswietlacz::rozejrzyjSieKasyno() {
    system("CLS");
	std::cout << "Wygląda jak kasyno." << std::endl;
	system("pause >nul");
}
void Wyswietlacz::pokazMenuRuletki() {
    system("CLS");
    std::cout << "--- RULETKA ---\n";
    std::cout << "Na co chcesz postawić swoje pieniądze?\n";
    std::cout << "1 - Konkretna liczba (0-36) [Wygrana 36x]\n";
    std::cout << "2 - Kolor (Czerwony / Czarny) [Wygrana 2x]\n";
    std::cout << "3 - Parzyste / Nieparzyste [Wygrana 2x]\n";
    std::cout << "Wybor: ";
}
void Wyswietlacz::pokazWynikRuletki(int wylosowanaLiczba, const std::string& kolor, long double wygranaKwota, long double stawka) {
    std::cout << "\nKrupier kręci kołem...\n";
    std::cout << "Kulka skacze... i zatrzymuje się na: " << wylosowanaLiczba << " [" << kolor << "]!\n\n";

    if (wygranaKwota > 0) {
        std::cout << "Gratulacje! Wygrywasz " << wygranaKwota << " zl!\n";
    }
    else {
        std::cout << "Niestety! Przegrywasz swoją stawkę (" << stawka << " zl).\n";
    }
}
void Wyswietlacz::chceszZagracPonownie() {
	std::cout << "Chcesz zagrać ponownie? (1 - Tak, 2 - Nie)" << std::endl;
}

//------------------------------INNE---------------------------------------

void Wyswietlacz::WYGRANA(int dni) {
	system("CLS");
    std::cout << "Gratulacje! Wygrałeś grę!" << std::endl;
	std::cout << "Udało Ci się to osiągnąć w: " << dni << " dni!" << std::endl;
	std::cout << "Dziękuję za grę!" << std::endl;
    system("pause >nul");
}

void Wyswietlacz::PRZEGRANA(int dni) {
	system("CLS");
	std::cout << "Niestety, zostałeś bankrutem :<" << std::endl;
	std::cout << "Udało Ci się być rekinem giełdowym przez: " << dni << " dni!" << std::endl;
	std::cout << "Powodzenia następnym razem!" << std::endl;
    system("pause >nul");
}