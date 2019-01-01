#include "domain/service/PoorManService.h"
#include "domain/service/AccountService.h"
#include "domain/service/ManService.h"
#include "domain/model/poor-man/PoorManRepo.h"
#include "domain/model/poor-man/PoorMan.h"

PoorManService::PoorManService()
{
	repo = getPoorManRepo();
}

std::string PoorManService::createMan(const std::string& name, Gender gender,
		const std::string& phoneNumber)
{
	auto manId = ManService().allocManId(name);
	auto man = new PoorMan(manId, name, gender, phoneNumber, 1000);
	repo->add(man);
	return manId;
}

void PoorManService::destroyMan(const std::string& manId)
{
	auto man = repo->remove(manId);
	delete man;
}
