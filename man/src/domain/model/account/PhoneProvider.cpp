#include "domain/model/account/PhoneProvider.h"


namespace
{
	PhoneProvider* phoneProvider = nullptr;
}

void setPhoneProvider(PhoneProvider* pp)
{
	phoneProvider = pp;
}

PhoneProvider* getPhoneProvider()
{
	return phoneProvider;
}
