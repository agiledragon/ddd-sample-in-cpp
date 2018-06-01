#include "domain/model/CargoProvider.h"

namespace
{
	CargoProvider* p = nullptr;
}

void setCargoProvider(CargoProvider* provider)
{
	p = provider;
}

CargoProvider* getCargoProvider()
{
	return p;
}
