#ifndef H0385833B_F099_4317_8B96_BD8FE422C768
#define H0385833B_F099_4317_8B96_BD8FE422C768

#include "domain/model/base/Role.h"
#include "pub/base/Types.h"
#include "domain/model/account/Balance.h"
#include "domain/model/account/Phone.h"
#include "domain/model/account/AccountInfo.h"

#include <string>

struct AccountInfo;
struct Balance;
struct Phone;

struct MoneyDest : Role
{
	void transferMoneyFrom(const std::string& srcAccountId, U32 amount) const;
	std::string getAccountId() const;

private:
	USE_ROLE(AccountInfo);
	USE_ROLE(Balance);
	USE_ROLE(Phone);
};



#endif
