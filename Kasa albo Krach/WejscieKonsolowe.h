#pragma once
#include "InterfejsWejscia.h"
#include <iostream>
class WejscieKonsolowe : public InterfejsWejscia
{
public:
	int pobierzInt() override;
	long double pobierzLongDouble() override;
	std::string pobierzString() override;
};

