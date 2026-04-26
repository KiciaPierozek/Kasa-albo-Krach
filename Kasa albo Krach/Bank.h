#pragma once
#include <string>
#include "Wyswietlacz.h"
#include "Kredyt.h"
#include "Placowka.h"
class Bank : public Placowka
{
private:
    int idBanku = 0;
    Kredyt kredyt;
    bool czyKredyt = false;

public:
	Bank() = default;
    Bank(const std::string& nazwa, int id_banku, const Kredyt& kredyt)
        : Placowka(nazwa),
        idBanku(id_banku),
        kredyt(kredyt) {
    }
    void ponaglij();
    void wejdz(Wyswietlacz& wyswietlacz, Gracz& gracz, int dni) const override {
		wyswietlacz.wBanku();
    }
    void zaciagnijKredyt();

    int getIdbanku(){
        return idBanku;
	}
    Kredyt& getKredyt() {
        return kredyt;
	}
    bool getCzyKredyt() {
        return czyKredyt;
    }
    void setCzyKredyt(bool czyKredyt_) {
        this->czyKredyt = czyKredyt_;
	}
};

