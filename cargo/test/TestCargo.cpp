#include "gtest/gtest.h"
#include "domain/service/CargoProvider.h"
#include "domain/model/CargoRepo.h"
#include "domain/model/Cargo.h"
#include "app/service/CargoApi.h"
#include "app/service/CargoMsg.h"
#include "domain/service/CargoService.h"

#include <vector>

namespace
{
	struct StubCargoProvider : CargoProvider
	{
		virtual void confirm(Cargo* cargo) override
		{
			cargoId = cargo->getId();
			afterDays = cargo->getAfterDays();
		}

		int cargoId;
		int afterDays;
	};

	struct StubCargoRepo : CargoRepo
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
		provider = new StubCargoProvider();
		repo = new StubCargoRepo();
		service = new CargoService(repo, provider);
		api = new CargoApi(service);
	}

	virtual void TearDown()
	{
		delete provider;
		delete repo;
		delete service;
		delete api;
	}

protected:
	StubCargoProvider* provider;
	CargoRepo* repo;
	CargoService* service;
	CargoApi* api;
};

TEST_F(CargoTest, create_cargo)
{
	CargoMsg msg(1, 10);
	api->createCargo(&msg);
	ASSERT_EQ(1, provider->cargoId);
	ASSERT_EQ(10, provider->afterDays);
}

TEST_F(CargoTest, delay_cargo)
{
	CargoMsg msg(2, 20);
	api->createCargo(&msg);
	ASSERT_EQ(2, provider->cargoId);
	api->delay(2, 5);
	ASSERT_EQ(2, provider->cargoId);
	ASSERT_EQ(25, provider->afterDays);
}

