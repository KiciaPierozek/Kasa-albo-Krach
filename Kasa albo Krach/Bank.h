#pragma once
#include <string>

#include "Kredyt.h"
#include "Placowka.h"
class Bank : public Placowka
{
private:
    int idBanku;
    Kredyt kredyt;

public:
    Bank(const std::string& nazwa, int id_banku, const Kredyt& kredyt)
        : Placowka(nazwa),
        idBanku(id_banku),
        kredyt(kredyt) {
    }
    void ponaglij();
    void wejdzDoBanku();
    void zaciagnijKredyt();

    int getIdbanku(){
        return idBanku;
	}
    Kredyt getKredyt() {
        return kredyt;
	}
};

