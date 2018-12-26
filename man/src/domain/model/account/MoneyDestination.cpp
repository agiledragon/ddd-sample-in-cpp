#include "domain/model/account/MoneyDestination.h"



void MoneyDestination::transferMoneyFrom(const std::string& srcAccountId, U32 amount) const
{
	ROLE(Balance).increase(amount);
	ROLE(Phone).sendTransferFromMsg(srcAccountId, amount);
}

std::string MoneyDestination::getAccountId() const
{
	return ROLE(AccountInfo).getAccountId();
}
