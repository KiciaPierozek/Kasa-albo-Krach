//
// Created by Admin on 22.04.2026.
//
#include <iostream>
#include "Wyswietlacz.h"
#include "Gracz.h"
#include "Silnik.h"
#include "Firma.h"
void Wyswietlacz::ekranPowitalny() {
    std::cout << R"(
$$\   $$\                                              $$\ $$\                       $$\   $$\                              $$\
$$ | $$  |                                             $$ |$$ |                      $$ | $$  |                             $$ |
$$ |$$  / $$$$$$\   $$$$$$$\  $$$$$$\         $$$$$$\  $$ |$$$$$$$\   $$$$$$\        $$ |$$  /  $$$$$$\  $$$$$$\   $$$$$$$\ $$$$$$$\
$$$$$  /  \____$$\ $$  _____| \____$$\        \____$$\ $$ |$$  __$$\ $$  __$$\       $$$$$  /  $$  __$$\ \____$$\ $$  _____|$$  __$$\
$$  $$<   $$$$$$$ |\$$$$$$\   $$$$$$$ |       $$$$$$$ |$$ |$$ |  $$ |$$ /  $$ |      $$  $$<   $$ |  \__|$$$$$$$ |$$ /      $$ |  $$ |
$$ |\$$\ $$  __$$ | \____$$\ $$  __$$ |      $$  __$$ |$$ |$$ |  $$ |$$ |  $$ |      $$ |\$$\  $$ |     $$  __$$ |$$ |      $$ |  $$ |
$$ | \$$\\$$$$$$$ |$$$$$$$  |\$$$$$$$ |      \$$$$$$$ |$$ |$$$$$$$  |\$$$$$$  |      $$ | \$$\ $$ |     \$$$$$$$ |\$$$$$$$\ $$ |  $$ |
\__|  \__|\_______|\_______/  \_______|       \_______|\__|\_______/  \______/       \__|  \__|\__|      \_______| \_______|\__|  \__|






Piotr Mleczko 2026                                                                                                                         )" << std::endl;
}

void Wyswietlacz::poczatekGry() {
    std::cout << "Nacisnij przycisk aby zagrać" << std::endl;
}

void Wyswietlacz::glowneMenu(Gracz& gracz) {
    std::cout << "Kapitał: " << gracz.getKapital() << std::endl;
    std::cout << "Środki: " << gracz.getSrodki() << std::endl;
    std::cout << "Co chcesz zrobić? " << std::endl;
    std::cout << "1 Idź do domu maklerskiego | 2 Idź do banku | 3 prześpij się (pomija dzień)" << std::endl;
}

void Wyswietlacz::uMaklera() {
    std::cout << "W domu maklerskim..." << std::endl;
    std::cout << "Co chcesz zrobić? " << std::endl;
    std::cout << "1 Sprawdź notowania | 2 Zarządzaj aktywami | 3 Rozejrzyj się | 4 Wyjdź" << std::endl;
}

void Wyswietlacz::sprawdzNotowania() {
    std::cout << "Notowania: " << std::endl;
    std::cout << "\t 1.  PAR" << std::endl;
    std::cout << "\t 2.  MKMK" << std::endl;
    std::cout << "\t 3.  GOGL" << std::endl;
    std::cout << "\t 4.  TRDM" << std::endl;
    std::cout << "\t 5.  KBC" << std::endl;
    std::cout << "\t 6.  SMSG" << std::endl;
    std::cout << "\t 7.  UŁ" << std::endl;
    std::cout << "\t 8.  KUKA" << std::endl;
    std::cout << "\t 9.  PPSI" << std::endl;
    std::cout << "\t 10. WZA" << std::endl;
    std::cout << "\t 11. PCKA" << std::endl;
    std::cout << "\t 12. MRSD" << std::endl;
    std::cout << "Której spółki?: ";
}

void Wyswietlacz::infoNotowanie(Firma& firma) {
    std::cout << firma.getNazwa() << " :" << std::endl;
    std::cout << "2 dni temu: " << firma.getAkcja().getCenaDwaDniPrzed() << "Różnica: " << firma.getAkcja().getCenaTrzyDniPrzed() << std::endl;
    std::cout << "1 dzień temu: " << firma.getAkcja().getCenaDzienPrzed() << std::endl;
    std::cout << "Dzisiaj: " << firma.getAkcja().getCena() << std::endl;
}

void Wyswietlacz::zarzadzajAktywami() {
}

void Wyswietlacz::sprzedajAktywo() {
}

void Wyswietlacz::rozejrzyjSieMakler() {
}

void Wyswietlacz::wBanku() {
}

void Wyswietlacz::warunkiKredytu(Bank& bank) {
}

void Wyswietlacz::branieKredytu() {
}

void Wyswietlacz::splacanieKredytu() {
}

void Wyswietlacz::rozejrzyjSieBank() {
}

void Wyswietlacz::przespijSie() {
}
