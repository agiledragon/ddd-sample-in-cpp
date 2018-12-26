#include "domain/service/RichManService.h"
#include "domain/service/AccountService.h"
#include "domain/model/rich-man/RichMan.h"
#include "domain/model/rich-man/RichManRepo.h"
#include "domain/service/ManService.h"


RichManService::RichManService()
{
	repo = getRichManRepo();
}

std::string RichManService::createMan(const std::string& name, Gender gender,
		const std::string& phoneNumber)
{
	auto manId = ManService().allocManId(name);
	auto man = new RichMan(manId, name, gender, phoneNumber, 10000);
	repo->add(man);
	return manId;
}

U32 RichManService::getAmount(const std::string& manId)
{
	auto man = repo->get(manId);
	auto accountId = SELF(*man, Boss).getAccountId();
	return AccountService().getAmount(accountId);
}

void RichManService::destroyMan(const std::string& manId)
{
	auto man = repo->remove(manId);
	delete man;
}

