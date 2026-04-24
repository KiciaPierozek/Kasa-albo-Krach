#pragma once
#include <string>
#include <vector>
#include "Akcje.h"
class Gracz
{
private:
    long double kapital;
    long double srodki;
    std::string nazwaGracza;
    int cel;
	std::vector<Akcje> posiadaneAkcje;
public:
    Gracz(long double kapital, long double srodki, std::string nazwa, unsigned int cel)
        : kapital(kapital), srodki(srodki), cel(cel), nazwaGracza(nazwa) {
    }

    long double getKapital() const {
        return kapital;
    }

    long double getSrodki() const {
        return srodki;
    }

    std::string getNazwaGracza() const {
        return nazwaGracza;
    }

    int getCel() const {
        return cel;
    }
    std::vector<Akcje> getPosiadaneAkcje() const {
        return posiadaneAkcje;
	}
};

