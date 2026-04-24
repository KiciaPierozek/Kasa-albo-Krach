#pragma once
#include "Wyswietlacz.h"
#include "Gracz.h"
#include "Firma.h"
#include "Bank.h"
#include "Akcje.h"
class Silnik
{
private:
    struct{
        const short naUlicy = 0;
        const short wDomuMaklerskim = 1;
        const short wBanku = 2;
        const short wKasynie = 3;
        const short przegrana = 4;
        const short wygrana = 5;
    }stanGry;
};

void glownaPetla() {
}