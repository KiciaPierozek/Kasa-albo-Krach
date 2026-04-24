#include <iostream>
#include <clocale>
#include <windows.h>
#include "Wyswietlacz.h"

int main() {
    std::setlocale(LC_ALL, "C.UTF-8");
    SetConsoleOutputCP(CP_UTF8);
    Wyswietlacz wyswietlacz;
    Gracz gracz(100, 200, "Kicia", 10000000);
    wyswietlacz.ekranPowitalny();
    wyswietlacz.poczatekGry();
    wyswietlacz.glowneMenu(gracz);
    wyswietlacz.uMaklera();
    wyswietlacz.sprawdzNotowania();
}
