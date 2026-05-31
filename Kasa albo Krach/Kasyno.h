//
// Created by Admin on 23.04.2026.
//

#ifndef SYMULATORGIELDY_KASYNO_H
#define SYMULATORGIELDY_KASYNO_H
#include "Placowka.h"

class Kasyno : public Placowka {

public:
	void wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const override;
};


#endif //SYMULATORGIELDY_KASYNO_H