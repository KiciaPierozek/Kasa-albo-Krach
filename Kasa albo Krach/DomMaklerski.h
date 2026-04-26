#pragma once
#include "Placowka.h"
#include "Wyswietlacz.h"
class Wyswietlacz;
class Gracz;
class DomMaklerski : public Placowka
{
public:
    void wejdz(Wyswietlacz& wyswietlacz, Gracz& gracz, int dni) const override {
        wyswietlacz.uMaklera();
	}
};

