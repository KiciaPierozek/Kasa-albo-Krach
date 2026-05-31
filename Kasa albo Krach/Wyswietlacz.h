#pragma once
#include "InterfejsWyswietlacza.h"

class Firma;
class Bank;
class Gracz;

class Wyswietlacz : public InterfejsWyswietlacza
{
public:
    Wyswietlacz() = default;
    ~Wyswietlacz() override = default;

    void ekranPowitalny() override;
    void poczatekGry() override;
    void uzueplnijDane1() override;
    void uzueplnijDane2() override;
    void wybierzPoziomTrudnosci() override;
    void glowneMenu(Gracz& gracz, int dni) override;
    void spytajOIlosc() override;
    void niepoprawnyWybor() override;
    void przespijSie() override;

    // DOM MAKLERSKI
    void uMaklera() override;
    void sprawdzNotowania() override;
    void spytajOKtore() override;
    void infoNotowanie(Firma& firma, long double cenaTrzyDni) override;
    void zarzadzajAktywami(Gracz& gracz) override;
    void Aktywo1(Gracz& gracz) override;
    void Aktywo2(Gracz& gracz) override;
    void sprzedajAktywo(Gracz& gracz) override;
    void rozejrzyjSieMakler() override;

    // BANK
    void wBanku() override;
    void warunkiKredytu(Bank& bank) override;
    void branieKredytu() override;
    void zlaKwotaKredytu() override;
    void nieMaszKredytu() override;
    void odrzucKredyt() override;
    void gratulacjeKredyt() override;
    void gratulacjeSplacenie() override;
    void splacanieKredytu(Gracz& gracz) override;
    void infoSplacenie(Gracz& gracz, long double kwota) override;
    void rozejrzyjSieBank() override;
    void ponaglenie10Dni() override;
    void ponaglenie5Dni() override;
    void ponaglenie1Dzien() override;
    void infoKwotaKredyt(Gracz& gracz) override;
	void grozaKredytowa(Gracz& gracz) override;

    // KASYNO
    void wKasynie() override;
    void wyborGry() override;
    void stawka() override;
    void blackJack() override;
    void obstaw() override;
    void ruletka() override;
    void kasynoWygrana(long double wygrana) override;
    void kasynoPrzegrana() override;
    void rozejrzyjSieKasyno() override;
};