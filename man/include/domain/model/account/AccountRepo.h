#ifndef H13D2C1E1_4A8B_411D_ACA9_461323B9B2D7
#define H13D2C1E1_4A8B_411D_ACA9_461323B9B2D7

#include "pub/base/Keywords.h"

#include <string>

struct Account;

struct AccountRepo
{
	virtual ~AccountRepo() = default;

	ABSTRACT(void add(Account* account));
	ABSTRACT(Account* get(const std::string& accountId));
	ABSTRACT(void update(Account* account));
	ABSTRACT(Account* remove(const std::string& accountId));
};

void setAccountRepo(AccountRepo* repo);
AccountRepo* getAccountRepo();

#endif
