#include "domain/service/ManService.h"

#include "../../../include/domain/model/poor-man/Employee.h"
#include "domain/model/rich-man/Boss.h"
#include "domain/service/AccountService.h"
#include "domain/model/rich-man/RichMan.h"
#include "domain/model/poor-man/PoorManRepo.h"
#include "domain/model/poor-man/PoorMan.h"
#include "domain/model/rich-man/RichManRepo.h"
#include "domain/model/base/Role.h"


ManService::ManService()
{
	richRepo = getRichManRepo();
	poorRepo = getPoorManRepo();
}

std::string ManService::allocManId(const std::string& name)
{
	return name + "123456";
}

void ManService::transferMoney(const std::string& richManId, const std::string& poorManId, U32 amount)
{
	auto richMan = richRepo->get(richManId);
	auto richAccountId = SELF(*richMan, Boss).getAccountId();

	auto poorMan = poorRepo->get(poorManId);
	auto poorAccountId = SELF(*poorMan, Employee).getAccountId();

	AccountService().transferMoney(richAccountId, poorAccountId, amount);

}
