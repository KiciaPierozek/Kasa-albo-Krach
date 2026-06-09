#include "WejscieKonsolowe.h"
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <sstream>

int WejscieKonsolowe::pobierzInt() {
    std::string tekst;
    int wartosc;

    while (true) {
        if (!std::getline(std::cin, tekst) || tekst.empty()) {
            continue;
        }

        try {
            size_t przetworzoneZnakow;
            long long temp = std::stoll(tekst, &przetworzoneZnakow);

            if (przetworzoneZnakow != tekst.length()) {
                throw std::invalid_argument("Smieci w tekscie");
            }

            if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max()) {
                throw std::out_of_range("Za duza liczba");
            }

            wartosc = static_cast<int>(temp);
            break;

        }
        catch (...) {
            std::cout << "Blad! Podana wartosc jest niepoprawna lub przekracza dopuszczalny zakres int!\n";
            std::cout << "Sprobuj ponownie: ";
        }
    }
    return wartosc;
}

long double WejscieKonsolowe::pobierzLongDouble() {
    std::string tekst;
    long double wartosc;

    while (true) {
        if (!std::getline(std::cin, tekst) || tekst.empty()) {
            continue;
        }

        if (tekst.length() > 25) {
            std::cout << "Blad! Ta liczba jest zbyt potezna dla gieldy!\n";
            std::cout << "Sprobuj ponownie: ";
            continue;
        }

        for (char& c : tekst) {
            if (c == ',') c = '.';
        }

        std::stringstream ss(tekst);

        if (ss >> wartosc) {

            std::string smieci;
            if (ss >> smieci) {
                std::cout << "Blad! Wpisano niedozwolone znaki (np. litery)!\n";
                std::cout << "Sprobuj ponownie: ";
                continue;
            }

            if (wartosc < 0) {
                std::cout << "Blad! Wartosc nie moze byc ujemna!\n";
                std::cout << "Sprobuj ponownie: ";
                continue;
            }

            break;
        }
        else {
            std::cout << "Blad! To nie jest poprawna liczba!\n";
            std::cout << "Sprobuj ponownie: ";
        }
    }

    return wartosc;
}

std::string WejscieKonsolowe::pobierzString() {
    std::string wartosc;
    while (std::getline(std::cin, wartosc)) {
        if (!wartosc.empty()) {
            break;
        }
    }
    return wartosc;
}