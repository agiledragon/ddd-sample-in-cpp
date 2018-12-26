#include "domain/model/account/Phone.h"
#include "domain/model/account/PhoneProvider.h"
#include "domain/model/account/AccountInfo.h"


Phone::Phone(const std::string& phoneNumber) : phoneNumber(phoneNumber)
{

}

bool Phone::operator==(ValueObject* rhs)
{
	return phoneNumber == dynamic_cast<Phone*>(rhs)->phoneNumber;
}

void Phone::sendTransferToMsg(const std::string& dstAccountId, U32 amount)
{
	getPhoneProvider()->send(phoneNumber, "%s send %u money to %s",
			ROLE(AccountInfo).getAccountId(), amount, dstAccountId);
}

void Phone::sendTransferFromMsg(const std::string& srcAccountId, U32 amount)
{
	getPhoneProvider()->send(phoneNumber, "%s receive %u money from %s",
				ROLE(AccountInfo).getAccountId(), amount, srcAccountId);
}
