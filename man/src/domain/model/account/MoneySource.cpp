#include "domain/model/account/MoneySource.h"
#include "domain/model/account/MoneyDestination.h"
#include "domain/model/account/AccountInfo.h"
#include "domain/model/account/Balance.h"
#include "domain/model/account/Phone.h"
#include "pub/log/log.h"


void MoneySource::transferMoneyTo(const MoneyDestination& dst, U32 amount)
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

U32 MoneySource::getAmount() const
{
	return ROLE(Balance).get();
}
