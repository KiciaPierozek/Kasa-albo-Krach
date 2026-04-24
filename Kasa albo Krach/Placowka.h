//
// Created by Admin on 22.04.2026.
//

#ifndef SYMULATORGIELDY_PLACOWKA_H
#define SYMULATORGIELDY_PLACOWKA_H
#include <string>
class Placowka {
protected:
    std::string nazwa;
    std::string skrot;
public:
    Placowka(std::string nazwa, std::string skrot)
        : nazwa(nazwa), skrot(skrot) {
    }
};
#endif //SYMULATORGIELDY_PLACOWKA_H