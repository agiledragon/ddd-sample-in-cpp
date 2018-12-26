#include "gtest/gtest.h"
#include "app/service/ManApi.h"
#include "domain/model/account/PhoneProvider.h"
#include "domain/model/poor-man/PoorManRepo.h"
#include "domain/model/rich-man/RichManRepo.h"
#include "domain/model/account/AccountRepo.h"
#include "domain/model/poor-man/PoorMan.h"
#include "domain/model/rich-man/RichMan.h"
#include "domain/model/account/Account.h"

#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
namespace
{
	struct PhoneMsg
	{
		U32 amount;
	};

	struct SpyPhoneProvider : PhoneProvider
	{
		OVERRIDE(void send(const std::string& phoneNumber, const std::string& format,
					const std::string& oneAccountId, U32 amount, const std::string& anotherAccountId))
			{
				msgs[phoneNumber] = PhoneMsg{amount};
			}

		std::map<std::string, PhoneMsg> msgs;
	};


	struct FakeAccountRepo : AccountRepo
	{
		OVERRIDE(void add(Account* account))
		{
			accounts.push_back(account);
		}

		OVERRIDE(Account* get(const std::string& accountId))
		{
			for (auto a : accounts)
			{
				if (a->getId() == accountId)
				{
					return a;
				}
			}
			return nullptr;
		}

		//simulate dbs operation
		OVERRIDE(void update(Account* account))
		{
			for (auto a : accounts)
			{
				if (a->getId() == account->getId())
				{
					remove(account->getId());
					add(account);

				}
			}

		}

		OVERRIDE(Account* remove(const std::string& accountId))
		{
			int i = 0;
			for (auto a : accounts)
			{
				if (a->getId() == accountId)
				{
					accounts.erase(accounts.begin() + i);
					return a;
				}
				i++;
			}
			return nullptr;
		}

	private:
		std::vector<Account*> accounts;
	};

	struct FakeRichManRepo : RichManRepo
	{
		OVERRIDE(void add(RichMan* man))
		{
			mans.push_back(man);
		}

		OVERRIDE(RichMan* get(const std::string& manId))
		{
			for (auto m : mans)
			{
				if (m->getId() == manId)
				{
					return m;
				}
			}
			return nullptr;
		}

		OVERRIDE(void update(RichMan* man))
		{
			for (auto m : mans)
			{
				if (m->getId() == man->getId())
				{
					remove(man->getId());
					add(man);

				}
			}
		}

		OVERRIDE(RichMan* remove(const std::string& manId))
		{
			int i = 0;
			for (auto m : mans)
			{
				if (m->getId() == manId)
				{
					mans.erase(mans.begin() + i);
					return m;
				}
				i++;
			}
			return nullptr;
		}

	private:
		std::vector<RichMan*> mans;
	};

	struct FakePoorManRepo : PoorManRepo
	{
		OVERRIDE(void add(PoorMan* man))
		{
			mans.push_back(man);
		}

		OVERRIDE(PoorMan* get(const std::string& manId))
		{
			for (auto m : mans)
			{
				if (m->getId() == manId)
				{
					return m;
				}
			}
			return nullptr;
		}

		OVERRIDE(void update(PoorMan* man))
		{
			for (auto m : mans)
			{
				if (m->getId() == man->getId())
				{
					remove(man->getId());
					add(man);

				}
			}

		}

		OVERRIDE(PoorMan* remove(const std::string& manId))
		{
			int i = 0;
			for (auto m : mans)
			{
				if (m->getId() == manId)
				{
					mans.erase(mans.begin() + i);
					return m;
				}
				i++;
			}
			return nullptr;
		}

	private:
		std::vector<PoorMan*> mans;
	};


}

struct TestMan : testing::Test
{

protected:
	virtual void SetUp()
	{
		provider = new SpyPhoneProvider();
		accountRepo = new FakeAccountRepo();
		poorRepo = new FakePoorManRepo();
		richRepo = new FakeRichManRepo();
		setPhoneProvider(provider);
		setAccountRepo(accountRepo);
		setRichManRepo(richRepo);
		setPoorManRepo(poorRepo);
		api = new ManApi();
		poorPhoneNumber = "19999999999";
		richPhoneNumber = "13333333333";
		richManId = api->createRichMan("zhangsan", richPhoneNumber);
		poorManId = api->createPoorMan("lisi", poorPhoneNumber);
	}

	virtual void TearDown()
	{
		api->destroyRichMan(richManId);
		api->destroyPoorMan(poorManId);
		delete api;
		delete provider;
		delete accountRepo;
		delete poorRepo;
		delete richRepo;
	}

protected:
	std::string richPhoneNumber;
	std::string poorPhoneNumber;
	ManApi* api;
	std::string richManId;
	std::string poorManId;
	SpyPhoneProvider* provider;
	FakeAccountRepo* accountRepo;
	FakePoorManRepo* poorRepo;
	FakeRichManRepo* richRepo;
};

TEST_F(TestMan, happy_new_year)
{
	const U32 RED_PACKET = 2000;
	U32 srcAmountStart = api->getRichManAmount(richManId);
	U32 dstAmountStart = api->getPoorManAmount(poorManId);

	api->happyNewYear2019(richManId, poorManId, RED_PACKET);

	U32 srcAmountEnd = api->getRichManAmount(richManId);
	U32 dstAmountEnd = api->getPoorManAmount(poorManId);

	ASSERT_EQ(RED_PACKET, srcAmountStart - srcAmountEnd);
	ASSERT_EQ(RED_PACKET, dstAmountEnd - dstAmountStart);

	auto sendedMsg = provider->msgs[richPhoneNumber];
	ASSERT_EQ(RED_PACKET, sendedMsg.amount);

	auto receivedMsg = provider->msgs[poorPhoneNumber];
	ASSERT_EQ(RED_PACKET, receivedMsg.amount);
}

