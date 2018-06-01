#include "app/service/CargoApi.h"
#include "domain/service/CargoService.h"
#include "domain/model/Cargo.h"

void createCargo(int cargoId, int afterDays)
{
	CargoService().create(cargoId, afterDays);
}

void delayCargo(int cargoId, int days)
{
	CargoService().delay(cargoId, days);
}

int getCargoAfterDays(int cargoId)
{
	return CargoService().getAfterDays(cargoId);
}
