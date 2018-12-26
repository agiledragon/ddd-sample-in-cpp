#ifndef H5DB5AB06_0930_4E92_BD5D_50A7A9FDA3A3
#define H5DB5AB06_0930_4E92_BD5D_50A7A9FDA3A3

#include "pub/base/Keywords.h"
#include "pub/base/Types.h"

#include <string>

struct PhoneProvider
{
	ABSTRACT(void send(const std::string& phoneNumber, const std::string& format,
			const std::string& oneAccountId, U32 amount, const std::string& anotherAccountId));

	virtual ~PhoneProvider() = default;
};

void setPhoneProvider(PhoneProvider* pp);
PhoneProvider* getPhoneProvider();

#endif
