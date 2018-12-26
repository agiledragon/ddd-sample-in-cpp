#ifndef HF21A9839_729E_4750_895E_340D6E468833
#define HF21A9839_729E_4750_895E_340D6E468833

#include "domain/model/base/ValueObject.h"
#include "pub/base/Keywords.h"
#include "domain/model/base/Role.h"
#include "pub/base/Types.h"

#include <string>

struct AccountInfo;

struct Phone : ValueObject
{
	Phone(const std::string& phoneNumber);

	OVERRIDE(bool operator==(ValueObject* rhs));

	void sendTransferToMsg(const std::string& dstAccountId, U32 amount);
	void sendTransferFromMsg(const std::string& srcAccountId, U32 amount);

private:
	USE_ROLE(AccountInfo);

private:
	std::string phoneNumber;
};


#endif
