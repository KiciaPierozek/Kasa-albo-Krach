#include "WejscieKonsolowe.h"
int WejscieKonsolowe::pobierzInt() {
	int wartosc;
	std::cin >> wartosc;
	return wartosc;
}
long double WejscieKonsolowe::pobierzLongDouble() {
	long double wartosc;
	std::cin >> wartosc;
	return wartosc;
}
std::string WejscieKonsolowe::pobierzString() {
	std::string wartosc;
	std::cin >> wartosc;
	return wartosc;
}