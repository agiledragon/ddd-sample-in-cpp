#include "domain/model/CargoFactory.h"
#include "domain/model/Delivery.h"
#include "domain/model/Cargo.h"

Cargo* CargoFactory::create(int cargoId, int afterDays)
{
	Delivery delivery(afterDays);
	return new Cargo(cargoId, delivery);
}
