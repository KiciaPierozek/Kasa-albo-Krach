#pragma once
#include <string>
class Akcje {
protected:
    long double cena;
    unsigned int numer;
    long double cenaTrzyDniPrzed;
    long double cenaDzienPrzed;
    long double cenaDwaDniPrzed;
    long double ilosc;
    std::string skrot;
public:
    Akcje(long double cena, unsigned int numer, long double cena_dzien_przed, long double cena_dwa_dni_przed, long double ilosc, std::string skrot, long double cenaTrzyDniPrzed_)
        : cena(cena),
        numer(numer),
        cenaDzienPrzed(cena_dzien_przed),
        cenaDwaDniPrzed(cena_dwa_dni_przed),
        ilosc(ilosc),
        skrot(skrot),
        cenaTrzyDniPrzed(cenaTrzyDniPrzed_){
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
    std::string getSkrot() {
        return skrot;
	}
    long double getIlosc() {
        return ilosc;
	}

    void setCena(long double cena_) {
        this->cena = cena_;
    }
    void setCenaDzienPrzed(long double cena_) {
        this->cenaDzienPrzed = cena_;
    }
    void setCenaDwaDniPrzed(long double cena_) {
        this -> cenaDwaDniPrzed = cena_;
    }
    void setCenaTrzyDniPrzed(long double cena_) {
        this->cenaTrzyDniPrzed = cena_;
    }
    void setIlosc(int ilosc_) {
        this->ilosc = ilosc_;

    }
};