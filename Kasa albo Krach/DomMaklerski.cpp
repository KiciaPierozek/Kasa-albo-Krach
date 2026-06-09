#include "DomMaklerski.h"
#include <iostream>
#include "Firma.h"
void DomMaklerski::wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const {
    if (wyswietlacz) {
        wyswietlacz->uMaklera();
    }
}
void DomMaklerski::KupAkcje(Gracz& gracz, Firma& firma, long double ilosc, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz) {
    if (ilosc == 0) {
        return;
    }
    long double koszt = firma.getAkcja().getCena() * ilosc;

    if (gracz.getSrodki() < koszt) {
        wyswietlacz->brakSrodkow();
        return;
    }

    std::vector<Akcje>& portfel = gracz.getPosiadaneAkcje();
    bool znaleziono = false;

    for (size_t i = 0; i < portfel.size(); ++i) {
        if (portfel[i].getSkrot() == firma.getAkcja().getSkrot()) {
            portfel[i].setIlosc(portfel[i].getIlosc() + ilosc);
            znaleziono = true;
            break;
        }
    }
    if (!znaleziono) {
        Akcje noweAkcje = firma.getAkcja();
        noweAkcje.setIlosc(ilosc);
        portfel.push_back(noweAkcje); 
    }

    gracz.setSrodki(gracz.getSrodki() - koszt);
	wyswietlacz->kupionoAkcje(firma, ilosc);
}
void DomMaklerski::sprzedajAkcje(Gracz& gracz, int ktore, long double ilosc, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz) {
    if (ktore <= 0 || ilosc <= 0) {
        wyswietlacz->nieprawidloweDane();
        return;
    }

    std::vector<Akcje>& portfel = gracz.getPosiadaneAkcje();
    int indeks = ktore - 1;

    if (indeks >= portfel.size()) {
        wyswietlacz->brakAkcjiNumer();
        return;
    }

    if (ilosc > portfel[indeks].getIlosc()) {
        wyswietlacz->brakTyleAkcji();
        return;
    }

    long double zarobek = portfel[indeks].getCena() * ilosc;
    gracz.setSrodki(gracz.getSrodki() + zarobek);

    portfel[indeks].setIlosc(portfel[indeks].getIlosc() - ilosc);

    wyswietlacz->akcjeSprzedane(ilosc);

    if (portfel[indeks].getIlosc() <= 0) {
        portfel.erase(portfel.begin() + indeks);
        wyswietlacz->usunietoAktywo();
    }
}