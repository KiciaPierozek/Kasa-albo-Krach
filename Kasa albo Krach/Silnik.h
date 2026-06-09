#pragma once
#include "Wyswietlacz.h"
#include "Gracz.h"
#include "Firma.h"
#include "Bank.h"
#include "Akcje.h"
#include "Ulica.h"
#include "DomMaklerski.h"
#include "Kasyno.h"
#include "InterfejsWejscia.h"
#include <vector>
#include <memory>
class Silnik
{
private:
    Gracz gracz;
    Bank peKO;
    std::shared_ptr<std::vector<Firma>> firmy = std::make_shared<std::vector<Firma>>();
    std::vector<Akcje> akcje;
    std::shared_ptr<Placowka> lokacja;
	std::shared_ptr<Bank> bank = std::make_shared<Bank>("PeKO", 1, Kredyt(0, 1, 2, 0));
    std::shared_ptr<Bank> wspeKO;
    std::shared_ptr<DomMaklerski> wsgielda;
    std::shared_ptr<Kasyno> wskasyno;
    std::shared_ptr<Ulica> wsulica;
    std::shared_ptr<InterfejsWyswietlacza> wyswietlacz;
	std::shared_ptr<InterfejsWejscia> wejscie;
    short wybor = 0;
    int dni = 1;

public:
    Silnik() {}
    void glownaPetla();
    void liczKapital(Gracz& gracz);
    void losujCenyAkcji(std::shared_ptr<std::vector<Firma>> firma, long double q);
    float losujOprocentowanie();
    void aktualizujCenyWPortfelu(Gracz& gracz, const std::vector<Firma>& wszystkieFirmy);
    int losujCzasKredytu();
	float losujStawkeKary(Bank& bank);
	void losujOferteBanku(Bank& bank);
    void wyplacDywidendy(Gracz& gracz, std::vector<Firma>& wszystkieFirmy);
	long double losujWspolczynnikZmianyCeny();
	void przespijSie();
    void pobierzKosztyZycia(Gracz& gracz);
    void start();
    void naUlicy();
    void wBanku();
	void wDomuMaklerskim();
    void wKasynie();
    void kupAkcje(Gracz& gracz, Firma& firma, long double ilosc);
    int getDni() {
        return dni;
	}
};
