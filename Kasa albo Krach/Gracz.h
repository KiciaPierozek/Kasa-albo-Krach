#pragma once
#include <string>
#include <vector>
#include "Akcje.h"
class Gracz
{
private:
    long double kapital = 0;
    long double srodki = 0;
    std::string nazwaGracza = "";
    int cel = 0;
    std::vector<Akcje> posiadaneAkcje;
public:
    Gracz() : kapital(0), srodki(0), nazwaGracza(""), cel(0), posiadaneAkcje() {}

    Gracz(long double kapital, long double srodki, std::string nazwa, unsigned int cel)
        : kapital(kapital), srodki(srodki), cel(cel), nazwaGracza(nazwa) {
    }

    long double getKapital() const {
        return kapital;
    }
    void setKapital(long double kapital_) {
        this->kapital = kapital_;
    }
    long double getSrodki() const {
        return srodki;
    }
    void setSrodki(long double srodki_) {
        this->srodki = srodki_;
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

