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
    Gracz gracz;
    std::shared_ptr<std::vector<Firma>> firmy = std::make_shared<std::vector<Firma>>();
    std::vector<Akcje> akcje;
    std::shared_ptr<Placowka> lokacja;
    std::shared_ptr<std::vector<Firma>> firma = firmy;

public:
    void glownaPetla();
    void losujCenyAkcji(std::vector<Firma>& firma, long double q);
	long double losujWspolczynnikZmianyCeny();
    void start();
};
