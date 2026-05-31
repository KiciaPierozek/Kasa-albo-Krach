#include "DomMaklerski.h"
void DomMaklerski::wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const {
    if (wyswietlacz) {
        wyswietlacz->uMaklera();
    }
}