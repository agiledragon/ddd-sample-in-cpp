#ifndef H6C53F302_5DB4_48E2_90DE_39A1E45AB6C5
#define H6C53F302_5DB4_48E2_90DE_39A1E45AB6C5

#include "pub/base/Types.h"
#include "pub/base/Keywords.h"
#include "domain/model/base/ValueObject.h"

#include <string>

struct AccountInfo : ValueObject
{
	AccountInfo(const std::string& accountId);

	OVERRIDE(bool operator==(ValueObject* rhs));

	std::string getAccountId() const;

private:
	std::string id;
};


#endif
