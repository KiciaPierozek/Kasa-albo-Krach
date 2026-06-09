//
// Created by Admin on 23.04.2026.
//

#ifndef SYMULATORGIELDY_KASYNO_H
#define SYMULATORGIELDY_KASYNO_H
#include "Placowka.h"
#include "Wyswietlacz.h"
#include "InterfejsWejscia.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <numeric>

class Kasyno : public Placowka {

public:
	void wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const override;
	void blackJack(Gracz& gracz, long double stawka, std::shared_ptr<InterfejsWejscia> wejscie, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz);
	void zagrajWRuletke(Gracz& gracz, long double stawka, std::shared_ptr<InterfejsWejscia> wejscie, std::shared_ptr<InterfejsWyswietlacza> wyswietlacz);
};


#endif //SYMULATORGIELDY_KASYNO_H