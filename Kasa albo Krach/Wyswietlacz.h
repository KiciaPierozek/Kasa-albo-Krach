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
    void glowneMenu(Gracz& gracz); // pierwszy wybor, dom maklerski, bank itp.
    //DOM MAKLERSKI

    void uMaklera();
    void sprawdzNotowania();
    void infoNotowanie(Firma& firma);
    void zarzadzajAktywami();
    void sprzedajAktywo();
    void rozejrzyjSieMakler();

    //BANK

    void wBanku();
    void warunkiKredytu(Bank& bank);
    void branieKredytu();
    void splacanieKredytu();
    void rozejrzyjSieBank();

    void przespijSie();

    //Kasyno
};

