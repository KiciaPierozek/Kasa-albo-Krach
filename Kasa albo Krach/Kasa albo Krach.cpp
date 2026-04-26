#include <iostream>
#include <clocale>
#include <windows.h>
#include "Wyswietlacz.h"
#include "Silnik.h"
#include "Firma.h"
#include "Bank.h"
#include "Kredyt.h"
#include "Ulica.h"
#include "DomMaklerski.h"
#include "Kasyno.h"
#include "Gracz.h"
#include "Placowka.h"
#include "Akcje.h"

int main() {
    std::setlocale(LC_ALL, "C.UTF-8");
    SetConsoleOutputCP(CP_UTF8);
    Silnik silnik; // instantiate object (avoid most-vexing-parse)
    silnik.start();
}
