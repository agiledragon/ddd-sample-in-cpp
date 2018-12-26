#ifndef H6C53F302_5DB4_48E2_90DE_39A1E45AB6C5
#define H6C53F302_5DB4_48E2_90DE_39A1E45AB6C5

#include "domain/model/account/Balance.h"
#include "domain/model/account/Phone.h"

#include <string>

struct AccountInfo
{
	AccountInfo(const std::string& accountId);

	std::string getAccountId() const;

private:
	std::string id;
};


#endif
