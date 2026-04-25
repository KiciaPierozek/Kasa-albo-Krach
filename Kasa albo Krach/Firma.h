#pragma once
#include <string>
#include "Placowka.h"
#include "Akcje.h"
class Firma : public Placowka
{
protected:
    long double wartosc;
    float dywidendy; //na jedna akcje
    unsigned int iloscAkcji;
    Akcje& akcja;
public:
    Firma(const std::string& nazwa, long double wartosc, float dywidendy,
        unsigned int ilosc_akcji, Akcje akcja)
        : Placowka(nazwa),
        wartosc(wartosc),
        dywidendy(dywidendy),
        iloscAkcji(ilosc_akcji),
        akcja(akcja) {
    }

    std::string getNazwa() {
        return nazwa;
    }
    double long getWartosc() {
        return wartosc;
    }
    float getDywidendy() {
        return dywidendy;
    }
    unsigned int getIloscAkcji() {
        return iloscAkcji;
    }
    Akcje getAkcja() {
        return akcja;
    }
};

