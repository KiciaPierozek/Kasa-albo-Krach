#pragma once
#include "Wyswietlacz.h"
#include "Gracz.h"
#include "Firma.h"
#include "Bank.h"
#include "Akcje.h"
#include "Ulica.h"
#include "DomMaklerski.h"
#include "Kasyno.h"
#include <vector>
#include <memory>
class Silnik
{
private:
    Wyswietlacz wyswietlacz;
    std::vector<Firma> firmy;
    std::vector<Akcje> akcje;
    std::shared_ptr<Placowka> lokacja; 

public:
    void glownaPetla();
    void losujCenyAkcji(std::vector<Firma>& firma, long double q);
	long double losujWspolczynnikZmianyCeny();
    void start();
};
