#pragma once
#include "Placowka.h"
#include "Wyswietlacz.h"
class Wyswietlacz;
class Gracz;
class Firma;
class DomMaklerski : public Placowka{
public:
	virtual ~DomMaklerski() override = default;
	void wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const override;
	void KupAkcje(Gracz& gracz, Firma& firma, long double ilosc, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz);
	void sprzedajAkcje(Gracz& gracz, int ktore, long double ilosc, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz);
};

