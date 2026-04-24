#pragma once
#include <iostream>
#include "Akcje.h"
#include "Bank.h"
#include "Firma.h"
class Wyswietlacz
{
public:
    Wyswietlacz() {}
    void ekranPowitalny();
    void poczatekGry();
    void uzueplnijDane1();
	void uzueplnijDane2();
    void glowneMenu(Gracz& gracz); // pierwszy wybor, dom maklerski, bank itp.
    //DOM MAKLERSKI

    void uMaklera();
    void sprawdzNotowania();
    void spytajOKtore();
    void infoNotowanie(Firma& firma, long double cenaTrzyDni);
    void zarzadzajAktywami(Gracz& gracz);
    void kupAktywo(Gracz& gracz);
    void sprzedajAktywo(Gracz& gracz);
    void rozejrzyjSieMakler();

    //BANK

    void wBanku();
    void warunkiKredytu(Bank& bank);
    void branieKredytu();
    void gratulacjeKredyt();
    void splacanieKredytu(Bank& bank);
    void rozejrzyjSieBank();

    void przespijSie();

    //Kasyno

    void wKasynie();
    void wyborGry();
    void graWybrana();
    void blackJack();
    void obstaw();
    void ruletka();
    void kasynoWygrana(long double wygrana);
	void kasynoPrzegrana();
    void rozejrzyjSieKasyno();

};

