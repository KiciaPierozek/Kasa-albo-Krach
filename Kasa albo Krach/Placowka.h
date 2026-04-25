#pragma once
//
// Created by Admin on 22.04.2026.
//

#ifndef SYMULATORGIELDY_PLACOWKA_H
#define SYMULATORGIELDY_PLACOWKA_H
#include <string>
#include "Gracz.h"
class Wyswietlacz;
class Gracz;
class Placowka {
protected:
    std::string nazwa;
public:
    Placowka(std::string nazwa)
        : nazwa(nazwa) {}
    virtual void wejdz(Wyswietlacz& wyswietlacz, Gracz& gracz) const = 0;
	virtual ~Placowka() {}
};
#endif //SYMULATORGIELDY_PLACOWKA_H