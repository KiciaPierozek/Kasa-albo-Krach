#pragma once
//
// Created by Admin on 22.04.2026.
//

#ifndef SYMULATORGIELDY_PLACOWKA_H
#define SYMULATORGIELDY_PLACOWKA_H
#include <string>
#include "Gracz.h"
#include <memory>
class InterfejsWyswietlacza;
class Gracz;
class Placowka {
protected:
    std::string nazwa = "";
public:

	Placowka() = default;
    Placowka(std::string nazwa)
        : nazwa(nazwa) {}
    virtual void wejdz(std::shared_ptr<InterfejsWyswietlacza> wyswietlacz, Gracz& gracz, int dni) const = 0;
	virtual ~Placowka() {}
};
#endif //SYMULATORGIELDY_PLACOWKA_H