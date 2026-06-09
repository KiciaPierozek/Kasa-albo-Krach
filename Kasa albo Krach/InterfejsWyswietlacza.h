#pragma once
#include <vector>
class Gracz;
class Firma;
class Bank;

class InterfejsWyswietlacza {
public:
    virtual ~InterfejsWyswietlacza() = default;

    virtual void ekranPowitalny() = 0;
    virtual void poczatekGry() = 0;
    virtual void uzueplnijDane1() = 0;
    virtual void uzueplnijDane2() = 0;
    virtual void wybierzPoziomTrudnosci() = 0;
    virtual void glowneMenu(Gracz& gracz, int dni) = 0;
    virtual void spytajOIlosc() = 0;
    virtual void niepoprawnyWybor() = 0;
    virtual void przespijSie() = 0;
	virtual void sprawdzWalorGracza(Gracz& gracz, int ktore) = 0;

    // DOM MAKLERSKI
    virtual void uMaklera() = 0;
    virtual void sprawdzNotowania(const std::vector<Firma>& wszystkieFirmy) = 0;
    virtual void spytajOKtore() = 0;
    virtual void infoNotowanie(Firma& firma) = 0;
    virtual void zarzadzajAktywami(Gracz& gracz) = 0;
    virtual void Aktywo1(Gracz& gracz) = 0;
    virtual void Aktywo2(Gracz& gracz) = 0;
    virtual void sprzedajAktywo() = 0;
    virtual void rozejrzyjSieMakler() = 0;
    virtual void nieprawidloweDane() = 0;
    virtual void kupionoAkcje(Firma firma, long double ilosc) = 0;
    virtual void brakAkcjiNumer() = 0;
    virtual void brakTyleAkcji() = 0;
	virtual void brakSrodkow() = 0;
	virtual void akcjeSprzedane(long double ilosc) = 0;
	virtual void usunietoAktywo() = 0;
    virtual void nieMaszAkcji() = 0;
	virtual void kosztyZycia(int jedzenie, int mieszkanie) = 0;
    virtual void otrzymanoDywidendy(long double calkowitaDywidenda) = 0;

    // BANK
    virtual void wBanku() = 0;
    virtual void warunkiKredytu(Bank& bank) = 0;
    virtual void branieKredytu() = 0;
    virtual void zlaKwotaKredytu() = 0;
    virtual void nieMaszKredytu() = 0;
    virtual void odrzucKredyt() = 0;
    virtual void gratulacjeKredyt() = 0;
    virtual void gratulacjeSplacenie() = 0;
    virtual void splacanieKredytu(Gracz& gracz) = 0;
    virtual void infoSplacenie(Gracz& gracz, long double kwota) = 0;
    virtual void rozejrzyjSieBank() = 0;
	virtual void ponaglenie10Dni() = 0;
	virtual void ponaglenie5Dni() = 0;
	virtual void ponaglenie1Dzien() = 0;
	virtual void infoKwotaKredyt(Gracz& gracz) = 0;
	virtual void grozaKredytowa(Gracz& gracz) = 0;

    // KASYNO
    virtual void wKasynie() = 0;
    virtual void wyborGry() = 0;
    virtual void stawka() = 0;
    virtual void blackJack() = 0;
    virtual void obstaw() = 0;
    virtual void ruletka() = 0;
    virtual void kasynoWygrana(long double wygrana) = 0;
    virtual void kasynoPrzegrana() = 0;
    virtual void rozejrzyjSieKasyno() = 0;
};