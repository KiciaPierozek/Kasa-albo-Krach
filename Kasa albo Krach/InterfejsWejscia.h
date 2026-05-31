#pragma once
#include <string>
class InterfejsWejscia
{
public:
	~InterfejsWejscia() = default;
	virtual int pobierzInt() = 0;
	virtual long double pobierzLongDouble() = 0;
	virtual std::string pobierzString() = 0;
};

