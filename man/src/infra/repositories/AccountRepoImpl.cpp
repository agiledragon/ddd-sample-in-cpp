#include "domain/model/account/AccountRepo.h"

struct AccountRepoImpl : AccountRepo
{
	OVERRIDE(void add(Account* account))
	{

	}

	OVERRIDE(Account* get(const std::string& accountId))
	{
		return nullptr;
	}

	OVERRIDE(void update(Account* account))
	{

	}

	OVERRIDE(Account* remove(const std::string& accountId))
	{
		return nullptr;
	}
};
