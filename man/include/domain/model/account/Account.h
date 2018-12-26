#ifndef H6AD9C42F_AC9B_42FE_B228_75DC6366A3C5
#define H6AD9C42F_AC9B_42FE_B228_75DC6366A3C5

#include "domain/model/base/AggregateRoot.h"
#include "domain/model/account/MoneySource.h"
#include "domain/model/account/MoneyDestination.h"
#include "domain/model/account/Balance.h"
#include "domain/model/account/Phone.h"
#include "domain/model/account/AccountInfo.h"

struct Account : AggregateRoot
			   , MoneySource
			   , MoneyDestination
			   , private AccountInfo
			   , private Balance
			   , private Phone
{
	Account(const std::string& accountId, const std::string& phoneNumber, U32 initialAmount);

private:
	IMPL_ROLE(AccountInfo);
	IMPL_ROLE(Balance);
	IMPL_ROLE(Phone);
};


#endif
