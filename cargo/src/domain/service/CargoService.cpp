#include "domain/service/CargoService.h"
#include "domain/model/Cargo.h"
#include "domain/model/CargoFactory.h"
#include "domain/model/CargoRepo.h"
#include "domain/model/CargoProvider.h"

CargoService::CargoService()
{
	repo = getCargoRepo();
	provider = getCargoProvider();
}

void CargoService::create(int cargoId, int afterDays)
{
	Cargo* cargo = CargoFactory().create(cargoId, afterDays);
	repo->add(cargo);
	provider->confirm(cargo);
}

void CargoService::delay(int cargoId, int delayDays)
{
	Cargo* cargo = repo->get(cargoId);
	if (cargo != nullptr)
	{
		cargo->delay(delayDays);
		repo->update(cargo);
		provider->confirm(cargo);
	}
}

int CargoService::getAfterDays(int cargoId)
{
	Cargo* cargo = repo->get(cargoId);
	if (cargo != nullptr)
	{
		return cargo->getAfterDays();
	}
	return INVALID_VALUE;
}

void CargoService::destroy(int cargoId)
{
	Cargo* cargo = repo->get(cargoId);
	if (cargo != nullptr)
	{
		repo->remove(cargoId);
		delete cargo;
	}
}
