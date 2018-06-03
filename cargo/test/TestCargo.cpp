#include "gtest/gtest.h"
#include "domain/model/CargoProvider.h"
#include "domain/model/CargoRepo.h"
#include "domain/model/Cargo.h"
#include "app/service/CargoApi.h"
#include "domain/service/CargoService.h"

#include <vector>

namespace
{
	struct SpyCargoProvider : CargoProvider
	{
		virtual void confirm(Cargo* cargo) override
		{
			cargoId = cargo->getId();
			afterDays = cargo->getAfterDays();
		}

		int cargoId;
		int afterDays;
	};

	struct FakeCargoRepo : CargoRepo
	{
		virtual void add(Cargo* cargo) override
		{
			cargoes.push_back(cargo);
		}

		virtual Cargo* get(int cargoId) override
		{
			for (Cargo* c : cargoes)
			{
				if (c->getId() == cargoId)
				{
					return c;
				}
			}
			return nullptr;
		}

		//simulate dbs operation
		virtual void update(Cargo* cargo) override
		{
			for (Cargo* c : cargoes)
			{
				if (c->getId() == cargo->getId())
				{
					remove(cargo->getId());
					add(cargo);

				}
			}

		}

		virtual void remove(int cargoId) override
		{
			int i = 0;
			for (Cargo* c : cargoes)
			{
				if (c->getId() == cargoId)
				{
					cargoes.erase(cargoes.begin() + i);
				}
				i++;
			}
		}

	private:
		std::vector<Cargo*> cargoes;
	};

}

struct CargoTest : testing::Test
{
	virtual void SetUp()
	{
		provider = new SpyCargoProvider();
		repo = new FakeCargoRepo();
		setCargoProvider(provider);
		setCargoRepo(repo);
	}

	virtual void TearDown()
	{
		delete provider;
		delete repo;
	}

protected:
	SpyCargoProvider* provider;
	CargoRepo* repo;
};

TEST_F(CargoTest, create_cargo)
{
	const int CARGO_ID = 1;
	const int AFTER_DAYS = 10;
	createCargo(CARGO_ID, AFTER_DAYS);
	int afterDays = getCargoAfterDays(CARGO_ID);
	ASSERT_EQ(CARGO_ID, provider->cargoId);
	ASSERT_EQ(AFTER_DAYS, provider->afterDays);
	ASSERT_EQ(AFTER_DAYS, afterDays);
}

TEST_F(CargoTest, delay_cargo)
{
	const int CARGO_ID = 1;
	const int AFTER_DAYS = 20;
	const int DAYS = 5;
	createCargo(CARGO_ID, AFTER_DAYS);
	delayCargo(CARGO_ID, DAYS);
	int afterDays = getCargoAfterDays(CARGO_ID);
	ASSERT_EQ(CARGO_ID, provider->cargoId);
	ASSERT_EQ(AFTER_DAYS + DAYS, provider->afterDays);
	ASSERT_EQ(AFTER_DAYS + DAYS, afterDays);
}

