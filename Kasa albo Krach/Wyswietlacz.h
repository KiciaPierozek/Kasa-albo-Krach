#pragma once
#include <iostream>
#include "Akcje.h"
#include "Firma.h"
class Gracz;
class Bank;
class Wyswietlacz
{
public:
    Wyswietlacz() {}
    void ekranPowitalny();
    void poczatekGry();
    void uzueplnijDane1();
	void uzueplnijDane2();
    void wybierzPoziomTrudnosci();
    void glowneMenu(Gracz& gracz); // pierwszy wybor, dom maklerski, bank itp.
    void spytajOIlosc();
    //DOM MAKLERSKI

    void uMaklera();
    void sprawdzNotowania();
    void spytajOKtore();
    void infoNotowanie(Firma& firma, long double cenaTrzyDni);
    void zarzadzajAktywami(Gracz& gracz);
    void Aktywo1(Gracz& gracz);
    void Aktywo2(Gracz& gracz);
    void sprzedajAktywo(Gracz& gracz);
    void rozejrzyjSieMakler();

    //BANK

    void wBanku();
    void warunkiKredytu(Bank& bank);
    void branieKredytu();
	void odrzucKredyt();
    void gratulacjeKredyt();
    void splacanieKredytu(Bank& bank);
    void infoSplacenie(Bank& bank, long double kwota);
    void rozejrzyjSieBank();

    void przespijSie();

    //Kasyno

    void wKasynie();
    void wyborGry();
    void stawka();
    void blackJack();
    void obstaw();
    void ruletka();
    void kasynoWygrana(long double wygrana);
	void kasynoPrzegrana();
    void rozejrzyjSieKasyno();

};

