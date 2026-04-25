#include <iostream>
#include <clocale>
#include <windows.h>
#include "Wyswietlacz.h"

int main() {
    std::setlocale(LC_ALL, "C.UTF-8");
    SetConsoleOutputCP(CP_UTF8);
}
