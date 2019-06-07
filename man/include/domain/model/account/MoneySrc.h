#ifndef HC4D3F84C_2419_47F5_BB99_C8B60666C57A
#define HC4D3F84C_2419_47F5_BB99_C8B60666C57A

#include "domain/model/base/Role.h"
#include "pub/base/Types.h"

struct AccountInfo;
struct Balance;
struct Phone;
struct MoneyDest;

struct MoneySrc : Role
{
	void transferMoneyTo(const MoneyDest& dst, U32 amount);
	U32 getAmount() const;

private:
	USE_ROLE(AccountInfo);
	USE_ROLE(Balance);
	USE_ROLE(Phone);
};


#endif
