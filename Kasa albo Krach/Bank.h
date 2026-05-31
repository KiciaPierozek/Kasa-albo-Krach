#pragma once
#include <string>
#include <memory>
#include "Placowka.h"
#include "Kredyt.h"

class InterfejsWyswietlacza;
class Gracz;

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

    void ponaglij(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz);

    void wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const override;

	void zbierzHaracz(Gracz& gracz, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz);

    int getIdbanku() {
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