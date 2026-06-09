#include "Kasyno.h"
void Kasyno::wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const {
	if (wyswietlacz) {
		wyswietlacz->wKasynie();
	}
}

void Kasyno::blackJack(Gracz& gracz, long double stawka, std::shared_ptr<InterfejsWejscia> wejscie, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz) {

    if (gracz.getSrodki() < stawka) {
        wyswietlacz->brakSrodkow();
        return;
    }
    gracz.setSrodki(gracz.getSrodki() - stawka);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::vector<std::string> talia = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

    auto dobierzKarte = [&]() -> std::string {
        std::uniform_int_distribution<int> dystrybucja(0, talia.size() - 1);
        return talia[dystrybucja(gen)];
        };

    auto policzPunkty = [](const std::vector<std::string>& reka) -> int {
        int suma = 0;
        int liczbaAsow = 0;
        for (const auto& karta : reka) {
            if (karta == "J" || karta == "Q" || karta == "K") suma += 10;
            else if (karta == "A") { suma += 11; liczbaAsow++; }
            else suma += std::stoi(karta);
        }
        while (suma > 21 && liczbaAsow > 0) { suma -= 10; liczbaAsow--; }
        return suma;
        };

    auto wypiszReke = [](const std::vector<std::string>& reka, bool ukrytaKarta = false) -> std::string {
        std::string wynik = "";
        for (size_t i = 0; i < reka.size(); ++i) {
            if (i == 1 && ukrytaKarta) wynik += "X";
            else wynik += reka[i];
        }
        return wynik;
        };

    std::vector<std::string> rekaGracza = { dobierzKarte(), dobierzKarte() };
    std::vector<std::string> rekaKrupiera = { dobierzKarte(), dobierzKarte() };
    bool graczPrzegralOdRazu = false;

    while (true) {

        wyswietlacz->pokazStanGryBlackjack(wypiszReke(rekaKrupiera, true), wypiszReke(rekaGracza), policzPunkty(rekaGracza));

        int punktyObecne = policzPunkty(rekaGracza);

        if (punktyObecne > 21) {
            wyswietlacz->fura(); 
            graczPrzegralOdRazu = true;
            break;
        }
        else if (punktyObecne == 21) {
            break;
        }

        wyswietlacz->wybierzKarte();
        int wybor = wejscie->pobierzInt();

        if (wybor == 1) {
            rekaGracza.push_back(dobierzKarte());
        }
        else if (wybor == 2) {
            break;
        }
    }

    if (!graczPrzegralOdRazu) {
        while (policzPunkty(rekaKrupiera) < 17) {
            rekaKrupiera.push_back(dobierzKarte());
        }
    }

    int pktGracza = policzPunkty(rekaGracza);
    int pktKrupiera = policzPunkty(rekaKrupiera);
    int rezultat = 0;

    if (graczPrzegralOdRazu) {
        rezultat = 2;
    }
    else if (pktKrupiera > 21) {
        rezultat = 1;
        gracz.setSrodki(gracz.getSrodki() + (stawka * 2));
    }
    else if (pktGracza > pktKrupiera) {
        rezultat = 1;
        gracz.setSrodki(gracz.getSrodki() + (stawka * 2));
    }
    else if (pktGracza < pktKrupiera) {
        rezultat = 2;
    }
    else {
        rezultat = 0;
        gracz.setSrodki(gracz.getSrodki() + stawka);
    }

    wyswietlacz->pokazWynikBlackjack(
        wypiszReke(rekaKrupiera), pktKrupiera,
        wypiszReke(rekaGracza), pktGracza,
        rezultat
    );

    system("pause");
}

void Kasyno::zagrajWRuletke(Gracz& gracz, long double stawka, std::shared_ptr<InterfejsWejscia> wejscie, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz) {
    if (gracz.getSrodki() < stawka) {
        std::cout << "Nie masz wystarczajacych srodkow na ten zaklad!\n";
        return;
    }
    gracz.setSrodki(gracz.getSrodki() - stawka);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dystrybucja(0, 36);

    auto sprawdzKolor = [](int liczba) -> std::string {
        if (liczba == 0) return "Zielony";
        std::vector<int> czerwone = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };

        if (std::find(czerwone.begin(), czerwone.end(), liczba) != czerwone.end()) {
            return "Czerwony";
        }
        return "Czarny";
        };

    wyswietlacz->pokazMenuRuletki();
    int typZakladu = wejscie->pobierzInt();

    int postawionaLiczba = -1;
    int postawionyKolor = -1;
    int postawionaParzystosc = -1;

    if (typZakladu == 1) {
        std::cout << "Podaj liczbe (0-36): ";
        while (true) {
            postawionaLiczba = wejscie->pobierzInt();
            if (postawionaLiczba >= 0 && postawionaLiczba <= 36) break;
            std::cout << "Nie ma takiej liczby na kole! Podaj od 0 do 36: ";
        }
    }
    else if (typZakladu == 2) {
        std::cout << "1 - Czerwony | 2 - Czarny: ";
        while (true) {
            postawionyKolor = wejscie->pobierzInt();
            if (postawionyKolor == 1 || postawionyKolor == 2) break;
            std::cout << "Wybierz 1 lub 2: ";
        }
    }
    else if (typZakladu == 3) {
        std::cout << "1 - Parzyste | 2 - Nieparzyste: ";
        while (true) {
            postawionaParzystosc = wejscie->pobierzInt();
            if (postawionaParzystosc == 1 || postawionaParzystosc == 2) break;
            std::cout << "Wybierz 1 lub 2: ";
        }
    }
    else {
        std::cout << "Nieprawidlowy wybor! Pieniadze wracaja na konto.\n";
        gracz.setSrodki(gracz.getSrodki() + stawka);
        system("pause");
        return;
    }

    int wylosowanaLiczba = dystrybucja(gen);
    std::string wylosowanyKolor = sprawdzKolor(wylosowanaLiczba);
    long double wygrana = 0;

    if (typZakladu == 1 && postawionaLiczba == wylosowanaLiczba) {
        wygrana = stawka * 36;
    }
    else if (typZakladu == 2 && wylosowanaLiczba != 0) {
        if ((postawionyKolor == 1 && wylosowanyKolor == "Czerwony") ||
            (postawionyKolor == 2 && wylosowanyKolor == "Czarny")) {
            wygrana = stawka * 2;
        }
    }
    else if (typZakladu == 3 && wylosowanaLiczba != 0) {
        bool wylosowanaJestParzysta = (wylosowanaLiczba % 2 == 0);
        if ((postawionaParzystosc == 1 && wylosowanaJestParzysta) ||
            (postawionaParzystosc == 2 && !wylosowanaJestParzysta)) {
            wygrana = stawka * 2;
        }
    }

    if (wygrana > 0) {
        gracz.setSrodki(gracz.getSrodki() + wygrana);
    }

    wyswietlacz->pokazWynikRuletki(wylosowanaLiczba, wylosowanyKolor, wygrana, stawka);
    system("pause");
}