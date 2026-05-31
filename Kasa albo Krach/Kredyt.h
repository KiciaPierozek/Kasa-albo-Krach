#pragma once
class Gracz;
class Kredyt
{
    long double wartosc = 0;
    float oprocentowanie = 0;
    int czas = 0;
    float stawkaKary = 0;
public:
	Kredyt() = default;
    Kredyt(double long wartosc, float oprocentowanie, int czas, float stawkaKary) : wartosc(wartosc), oprocentowanie(oprocentowanie), czas(czas), stawkaKary(stawkaKary) {}
    void splac(double kwota);
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
    void setWartosc(long double wartosc_) {
        this->wartosc = wartosc_;
	}
    void setOprocentowanie(float oprocentowanie_) {
        this->oprocentowanie = oprocentowanie_;
    }
    void setCzas(int czas_) {
        this->czas = czas_;
    }
    void setStawkaKary(float stawkaKary_) {
        this->stawkaKary = stawkaKary_;
    }
	void oprocentowanieDziennie() {
		this->wartosc += this->wartosc * this->oprocentowanie;
	}
    void uplywDni() {
        if (czas > 0) {
            czas--;
        }
    }
};

