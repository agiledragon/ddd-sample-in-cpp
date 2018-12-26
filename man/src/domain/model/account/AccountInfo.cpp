#include "domain/model/account/AccountInfo.h"


AccountInfo::AccountInfo(const std::string& accountId) : id(accountId)
{

}

std::string AccountInfo::getAccountId() const
{
	return id;
}
