#pragma once
#include "Placowka.h"
#include "Wyswietlacz.h"
class Gracz;
class Ulica : public Placowka
{
	public:
		Ulica() {};
	Ulica(const std::string& nazwa) : Placowka(nazwa) {}
	void wejdz(Wyswietlacz& wyswietlacz, Gracz& gracz) const override {
		wyswietlacz.glowneMenu(gracz);
	}
};

