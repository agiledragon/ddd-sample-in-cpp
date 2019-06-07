#include "domain/model/account/AccountInfo.h"


AccountInfo::AccountInfo(const std::string& accountId) : id(accountId)
{

}

bool AccountInfo::operator==(ValueObject* rhs)
{
	return id == dynamic_cast<AccountInfo*>(rhs)->id;
}

std::string AccountInfo::getAccountId() const
{
	return id;
}
