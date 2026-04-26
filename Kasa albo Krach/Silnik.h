#pragma once
#include "Wyswietlacz.h"
#include "Gracz.h"
#include "Firma.h"
#include "Bank.h"
#include "Akcje.h"
#include "Ulica.h"
#include "DomMaklerski.h"
#include "Kasyno.h"
#include <vector>
#include <memory>
class Silnik
{
private:
    Wyswietlacz wyswietlacz;
    Gracz gracz;
    Bank peKO;
    std::shared_ptr<std::vector<Firma>> firmy = std::make_shared<std::vector<Firma>>();
    std::vector<Akcje> akcje;
    std::shared_ptr<Placowka> lokacja;
    std::shared_ptr<std::vector<Firma>> firma = firmy;
	std::shared_ptr<Bank> bank = std::make_shared<Bank>("PeKO", 1, Kredyt(0, 1, 2, 0));
    std::shared_ptr<Bank> wspeKO;
    std::shared_ptr<DomMaklerski> wsgielda;
    std::shared_ptr<Kasyno> wskasyno;
    std::shared_ptr<Ulica> wsulica;
    short wybor = 0;
    int dni = 1;

public:
    Silnik() {}
    void glownaPetla();
    void losujCenyAkcji(std::vector<Firma>& firma, long double q);
    float losujOprocentowanie();
    int losujCzasKredytu();
	float losujStawkeKary(Bank& bank);
	void losujOferteBanku(Bank& bank);
	long double losujWspolczynnikZmianyCeny();
	void przespijSie();
    void start();
    void naUlicy();
    void wBanku();
	void wDomuMaklerskim();
    void wKasynie();
    int getDni() {
        return dni;
	}
};
