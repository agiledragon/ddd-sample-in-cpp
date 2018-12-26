#include "domain/model/account/PhoneProvider.h"

struct PhoneProviderImpl : PhoneProvider
{
	OVERRIDE(void send(const std::string& phoneNumber, const std::string& format,
			const std::string& oneAccountId, U32 amount, const std::string& anotherAccountId))
	{

	}

};
