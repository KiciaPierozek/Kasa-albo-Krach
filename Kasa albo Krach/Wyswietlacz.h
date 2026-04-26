#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Akcje.h"
#include "Firma.h"
class Silnik;
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
    void glowneMenu(Gracz& gracz, int dni); // pierwszy wybor, dom maklerski, bank itp.
    void spytajOIlosc();
    void niepoprawnyWybor();
    void przespijSie();
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
    void zlaKwotaKredytu();
    void nieMaszKredytu();
	void odrzucKredyt();
    void gratulacjeKredyt();
    void gratulacjeSplacenie();
    void splacanieKredytu(Bank& bank);
    void infoSplacenie(Bank& bank, long double kwota);
    void rozejrzyjSieBank();

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

