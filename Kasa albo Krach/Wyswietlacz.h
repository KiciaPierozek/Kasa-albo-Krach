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
    void sprawdzNotowania1(const std::vector<Firma>& wszystkieFirmy) override;
    void sprawdzNotowania2(const std::vector<Firma>& wszystkieFirmy) override;
    void spytajOKtore() override;
    void infoNotowanie(Firma& firma) override;
    void zarzadzajAktywami(Gracz& gracz) override;
    void Aktywo1(Gracz& gracz) override;
    void Aktywo2(Gracz& gracz) override;
    void sprzedajAktywo() override;
    void rozejrzyjSieMakler() override;
    void sprawdzWalorGracza(Gracz& gracz, int ktore) override;
    void nieprawidloweDane() override;
	void kupionoAkcje(Firma firma, long double ilosc) override;
	void brakAkcjiNumer() override;
	void brakTyleAkcji() override;
	void brakSrodkow() override;
	void akcjeSprzedane(long double ilosc) override;
	void nieMaszAkcji() override;
    void usunietoAktywo() override;
	void kosztyZycia(int jedzenie, int mieszkanie) override;
	void otrzymanoDywidendy(long double calkowitaDywidenda) override;
	void wyswietlOstatniDzien(std::vector<Firma>& wszystkieFirmy) override;

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
	void maszKredyt() override;

    // KASYNO
    void wKasynie() override;
    void wyborGry() override;
    void stawka() override;
    void kasynoWygrana(long double wygrana) override;
    void kasynoPrzegrana() override;
    void rozejrzyjSieKasyno() override;
    void pokazStanGryBlackjack(const std::string& kartyKrupiera, const std::string& kartyGracza, int punktyGracza) override;
    void pokazWynikBlackjack(const std::string& kartyKrupiera, int pktKrupiera, const std::string& kartyGracza, int pktGracza, int rezultat) override;
	void nieMaszSrodkow() override;
	void fura() override;
	void wybierzKarte() override;
    void pokazMenuRuletki() override;
    void pokazWynikRuletki(int wylosowanaLiczba, const std::string& kolor, long double wygranaKwota, long double stawka) override;
	void chceszZagracPonownie() override;
	void podajLiczbe() override;
	void nieMaLiczby() override;
	void czerwonyCzarny() override;
	void parzysteNieparzyste() override;
	void wybierzJD() override;
	void nieprawidlowyWyborKasyno() override;
    

    //INNE
    void WYGRANA(int dni) override;
	void PRZEGRANA(int dni) override;
};