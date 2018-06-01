#include "domain/model/CargoRepo.h"

struct CargoRepoImpl : CargoRepo
{
	virtual void add(Cargo* cargo) override
	{

	}

	virtual Cargo* get(int cargoId) override
	{
		return nullptr;
	}

	virtual void update(Cargo* cargo) override
	{

	}

	virtual void remove(int cargoId) override
	{

	}
};
