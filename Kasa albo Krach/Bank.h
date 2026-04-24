#pragma once
#include <string>

#include "Kredyt.h"
#include "Placowka.h"
class Bank : public Placowka
{
private:
    int idBanku;
    float stawka;
    Kredyt kredyt;

public:
    Bank(const std::string& nazwa, int id_banku, float stawka, const Kredyt& kredyt)
        : Placowka(nazwa),
        idBanku(id_banku),
        stawka(stawka),
        kredyt(kredyt) {
    }
    void ponaglij();
    void wyplacOdsetki();
    void wejdzDoBanku();
    void zaciagnijKredyt();

    int getIdbanku(){
        return idBanku;
	}
    float getStawka() {
        return stawka;
    }
    Kredyt getKredyt() {
        return kredyt;
	}
};

