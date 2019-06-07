#include "domain/model/account/MoneyDest.h"



void MoneyDest::transferMoneyFrom(const std::string& srcAccountId, U32 amount) const
{
	ROLE(Balance).increase(amount);
	ROLE(Phone).sendTransferFromMsg(srcAccountId, amount);
}

std::string MoneyDest::getAccountId() const
{
	return ROLE(AccountInfo).getAccountId();
}
