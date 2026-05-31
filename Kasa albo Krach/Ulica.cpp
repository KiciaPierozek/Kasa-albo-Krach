#include "Ulica.h"
void Ulica::wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const {
    if (wyswietlacz) {
        wyswietlacz->glowneMenu(gracz, dni);
    }
}