#include "domain/model/account/AccountRepo.h"

namespace
{
	AccountRepo* accountRepo = nullptr;
}

void setAccountRepo(AccountRepo* repo)
{
	accountRepo = repo;
}

AccountRepo* getAccountRepo()
{
	return accountRepo;
}
