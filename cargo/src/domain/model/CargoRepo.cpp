#include "domain/model/CargoRepo.h"

namespace
{
	CargoRepo* p = nullptr;
}

void setCargoRepo(CargoRepo* repo)
{
	p = repo;
}

CargoRepo* getCargoRepo()
{
	return p;
}

