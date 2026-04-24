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
    Akcje akcja;
public:
    Firma(const std::string& nazwa, const std::string& skrot, long double wartosc, float dywidendy,
        unsigned int ilosc_akcji, const Akcje& akcja)
        : Placowka(nazwa, skrot),
        wartosc(wartosc),
        dywidendy(dywidendy),
        iloscAkcji(ilosc_akcji),
        akcja(akcja) {
    }

    std::string getNazwa() {
        return nazwa;
    }
    std::string getSkrot() {
        return skrot;
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

