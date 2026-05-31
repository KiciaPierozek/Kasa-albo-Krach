#pragma once
#include "Placowka.h"
#include "Wyswietlacz.h"
class Wyswietlacz;
class Gracz;
class DomMaklerski : public Placowka
{
public:
	void wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const override;
};

