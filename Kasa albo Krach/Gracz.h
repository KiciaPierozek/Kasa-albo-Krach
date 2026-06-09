#pragma once
#include <string>
#include <vector>
#include "Akcje.h"
#include "Kredyt.h"
class Gracz
{
private:
    long double kapital = 0;
    long double srodki = 0;
    std::string nazwaGracza = "";
    int cel = 0;
    std::vector<Akcje> posiadaneAkcje;
    Kredyt kredytGracza;
public:
    Gracz() : kapital(0), srodki(0), nazwaGracza(""), cel(0), posiadaneAkcje() {}

    Gracz(long double kapital, long double srodki, std::string nazwa, int cel)
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
    std::vector<Akcje>& getPosiadaneAkcje() {
        return posiadaneAkcje;
	}
	Kredyt& getKredytGracza() {
		return kredytGracza;
	}
	void setKredytGracza(const Kredyt& kredyt) {
		this->kredytGracza = kredyt;
	}
};

