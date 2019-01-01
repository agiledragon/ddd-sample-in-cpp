#include "domain/service/TransferMoney.h"
#include "domain/model/account/AccountRepo.h"
#include "domain/model/account/Account.h"
#include "domain/model/poor-man/PoorManRepo.h"
#include "domain/model/poor-man/PoorMan.h"
#include "domain/model/rich-man/RichManRepo.h"
#include "domain/model/rich-man/RichMan.h"
#include "domain/model/base/Role.h"

void transferMoney(const std::string& richManId, const std::string& poorManId, U32 amount)
{
	auto richRepo = getRichManRepo();
	auto richMan = richRepo->get(richManId);
	auto richAccountId = SELF(*richMan, Boss).getAccountId();

	auto poorRepo = getPoorManRepo();
	auto poorMan = poorRepo->get(poorManId);
	auto poorAccountId = SELF(*poorMan, Employee).getAccountId();

	auto accountRepo = getAccountRepo();
	auto srcAccount = accountRepo->get(richAccountId);
	auto dstAccount = accountRepo->get(poorAccountId);
	SELF(*srcAccount, MoneySource).transferMoneyTo(SELF(*dstAccount, MoneyDestination), amount);
}
