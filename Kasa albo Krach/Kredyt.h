#pragma once
#include "Gracz.h"
class Kredyt
{
    long double wartosc;
    float oprocentowanie;
    int czas;
    float stawkaKary;
public:
    Kredyt(double long wartosc, float oprocentowanie, int czas, float stawkaKary) : wartosc(wartosc), oprocentowanie(oprocentowanie), czas(czas), stawkaKary(stawkaKary) {}
    void splac(double kwota);
    void pobierzKare(double stawka, Gracz& gracz);
    long double getWartosc() const {
        return wartosc;
	}
    float getOprocentowanie() const {
        return oprocentowanie;
    }
    int getCzas() const {
        return czas;
    }
    float getStawkaKary() const {
        return stawkaKary;
	}
};

