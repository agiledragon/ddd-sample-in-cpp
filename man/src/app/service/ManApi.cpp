#include "app/service/ManApi.h"
#include "domain/service/TransferMoney.h"

#include <stdlib.h>

ManApi::ManApi()
: richManService(RichManService()), poorManService(PoorManService()), amounQuery(AmountQuery())
{

}

std::string ManApi::createRichMan(const std::string& name, const std::string& phoneNumber)
{
	auto gender = decideGender();
	return richManService.createMan(name, gender, phoneNumber);
}

std::string ManApi::createPoorMan(const std::string& name, const std::string& phoneNumber)
{
	auto gender = decideGender();
	return poorManService.createMan(name, gender, phoneNumber);
}

U32 ManApi::getRichManAmount(const std::string& manId)
{
	return amounQuery.getRichManAmount(manId);
}

U32 ManApi::getPoorManAmount(const std::string& manId)
{
	return amounQuery.getPoorManAmount(manId);
}

void ManApi::happyNewYear2019(const std::string& richManId, const std::string& poorManId, U32 amount)
{
	transferMoney(richManId, poorManId, amount);
}

void ManApi::destroyRichMan(const std::string& manId)
{
	richManService.destroyMan(manId);
}

void ManApi::destroyPoorMan(const std::string& manId)
{
	poorManService.destroyMan(manId);
}

Gender ManApi::decideGender()
{
	return rand() % 2 == 0 ? MALE : FEMALE;
}

