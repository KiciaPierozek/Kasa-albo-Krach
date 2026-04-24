#pragma once
#include <string>
class Akcje {
protected:
    long double cena;
    unsigned int numer;
    long double cenaTrzyDniPrzed;
    long double cenaDzienPrzed;
    long double cenaDwaDniPrzed;
public:
    Akcje(long double cena, unsigned int numer, long double cena_dzien_przed, long double cena_dwa_dni_przed)
        : cena(cena),
        numer(numer),
        cenaDzienPrzed(cena_dzien_przed),
        cenaDwaDniPrzed(cena_dwa_dni_przed) {
    }

    long double getCena() {
        return cena;
    }
    unsigned int getNumer() {
        return numer;
    }
    long double getCenaDzienPrzed() {
        return cenaDzienPrzed;
    }
    long double getCenaDwaDniPrzed() {
        return cenaDwaDniPrzed;
    }
    long double getCenaTrzyDniPrzed() {
        return cenaTrzyDniPrzed;
    }
};