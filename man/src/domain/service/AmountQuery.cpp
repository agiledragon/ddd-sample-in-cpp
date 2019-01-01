#include "domain/service/AmountQuery.h"
#include "domain/model/account/AccountRepo.h"
#include "domain/model/account/Account.h"
#include "domain/model/poor-man/PoorManRepo.h"
#include "domain/model/poor-man/PoorMan.h"
#include "domain/model/rich-man/RichManRepo.h"
#include "domain/model/rich-man/RichMan.h"
#include "domain/model/base/Role.h"


AmountQuery::AmountQuery()
{
	richRepo = getRichManRepo();
	poorRepo = getPoorManRepo();
	accountRepo = getAccountRepo();
}

U32 AmountQuery::getRichManAmount(const std::string& manId)
{
	auto richMan = richRepo->get(manId);
	auto accountId = SELF(*richMan, Boss).getAccountId();


	auto account = accountRepo->get(accountId);
	return SELF(*account, MoneySource).getAmount();
}

U32 AmountQuery::getPoorManAmount(const std::string& manId)
{
	auto poorMan = poorRepo->get(manId);
	auto accountId = SELF(*poorMan, Employee).getAccountId();

	auto accountRepo = getAccountRepo();
	auto account = accountRepo->get(accountId);
	return SELF(*account, MoneySource).getAmount();
}
