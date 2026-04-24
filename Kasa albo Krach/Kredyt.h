#pragma once
#include "Gracz.h"
class Kredyt
{
    double long wartosc;
    float oprocentowanie;
    int czas;
    float stawkaKary;
public:
    Kredyt(double long wartosc, float oprocentowanie, int czas, float stawkaKary) : wartosc(wartosc), oprocentowanie(oprocentowanie), czas(czas), stawkaKary(stawkaKary) {}
    void splac(double kwota);
    void pobierzKare(double stawka, Gracz& gracz);
};

