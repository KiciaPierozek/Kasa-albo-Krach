#pragma once
#include "Placowka.h"
#include "Wyswietlacz.h"
class Wyswietlacz;
class Gracz;
class DomMaklerski : public Placowka
{
public:
    void wejdz(Wyswietlacz& wyswietlacz, Gracz& gracz) const override {
        wyswietlacz.uMaklera();
	}
};

