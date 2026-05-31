#include "Bank.h"
#include "InterfejsWyswietlacza.h"
#include "Gracz.h"


void Bank::wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const {
    if (wyswietlacz) {
        wyswietlacz->wBanku();
    }
}

void Bank::ponaglij(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz) {
    if (gracz.getKredytGracza().getCzas() == 10) {
        wyswietlacz->ponaglenie10Dni();
        wyswietlacz->infoKwotaKredyt(gracz);
    }
    if (gracz.getKredytGracza().getCzas() == 5) {
        wyswietlacz->ponaglenie5Dni();
        wyswietlacz->infoKwotaKredyt(gracz);
    }
	if (gracz.getKredytGracza().getCzas() == 1) {
		wyswietlacz->ponaglenie1Dzien();
		wyswietlacz->infoKwotaKredyt(gracz);
	}
}

void Bank::zbierzHaracz(Gracz& gracz, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz) {
    if (gracz.getKredytGracza().getCzas() == 0 && gracz.getKredytGracza().getWartosc() > 0) {
		wyswietlacz->grozaKredytowa(gracz);
        long double calkowitePotracenie = gracz.getKredytGracza().getWartosc() * (1.0L + gracz.getKredytGracza().getStawkaKary());
        gracz.setSrodki(gracz.getSrodki() - calkowitePotracenie);
        gracz.getKredytGracza().setCzas(-1);
    }
}