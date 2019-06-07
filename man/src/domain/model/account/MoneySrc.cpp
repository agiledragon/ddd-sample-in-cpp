#include "domain/model/account/MoneySrc.h"
#include "domain/model/account/MoneyDest.h"
#include "domain/model/account/AccountInfo.h"
#include "domain/model/account/Balance.h"
#include "domain/model/account/Phone.h"
#include "pub/log/log.h"


void MoneySrc::transferMoneyTo(const MoneyDest& dst, U32 amount)
{
	if (ROLE(Balance).get() < amount)
	{
		ERR_LOG("insufficient money!");
		return;
	}
	ROLE(AccountInfo).getAccountId();
	dst.transferMoneyFrom(ROLE(AccountInfo).getAccountId(), amount);
	ROLE(Balance).decrease(amount);
	ROLE(Phone).sendTransferToMsg(dst.getAccountId(), amount);
}

U32 MoneySrc::getAmount() const
{
	return ROLE(Balance).get();
}
