class IWyswietlacz
{
public:
    virtual ~IWyswietlacz() = default;

    virtual void ekranPowitalny() = 0;
    virtual void poczatekGry() = 0;
    virtual void uzueplnijDane1() = 0;
    virtual void uzueplnijDane2() = 0;
    virtual void wybierzPoziomTrudnosci() = 0;
    virtual void glowneMenu(Gracz& gracz, int dni) = 0;
    virtual void spytajOIlosc() = 0;
    virtual void niepoprawnyWybor() = 0;
    virtual void przespijSie() = 0;

    // DOM MAKLERSKI
    virtual void uMaklera() = 0;
    virtual void sprawdzNotowania() = 0;
    virtual void spytajOKtore() = 0;
    virtual void infoNotowanie(Firma& firma, long double cenaTrzyDni) = 0;
    virtual void zarzadzajAktywami(Gracz& gracz) = 0;
    virtual void Aktywo1(Gracz& gracz) = 0;
    virtual void Aktywo2(Gracz& gracz) = 0;
    virtual void sprzedajAktywo(Gracz& gracz) = 0;
    virtual void rozejrzyjSieMakler() = 0;

    // BANK
    virtual void wBanku() = 0;
    virtual void warunkiKredytu(Bank& bank) = 0;
    virtual void branieKredytu() = 0;
    virtual void zlaKwotaKredytu() = 0;
    virtual void nieMaszKredytu() = 0;
    virtual void odrzucKredyt() = 0;
    virtual void gratulacjeKredyt() = 0;
    virtual void gratulacjeSplacenie() = 0;
    virtual void splacanieKredytu(Bank& bank) = 0;
    virtual void infoSplacenie(Bank& bank, long double kwota) = 0;
    virtual void rozejrzyjSieBank() = 0;

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