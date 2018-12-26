#include "domain/service/AccountService.h"
#include "domain/model/account/AccountRepo.h"
#include "domain/model/account/Account.h"
#include "domain/model/base/Role.h"

AccountService::AccountService()
{
	repo = getAccountRepo();
}

std::string AccountService::createAccount(const std::string& manId, const std::string& phoneNumber, U32 initAmount)
{
	auto accountId = manId.substr(2) + "888";
	auto account = new Account(accountId, phoneNumber, initAmount);
	repo->add(account);
	return accountId;
}

void AccountService::transferMoney(const std::string& srcAccountId, const std::string& dstAccountId, U32 amount)
{
	auto srcAccount = repo->get(srcAccountId);
	auto dstAccount = repo->get(dstAccountId);
	SELF(*srcAccount, MoneySource).transferMoneyTo(*dstAccount, amount);
}

U32 AccountService::getAmount(const std::string& accountId)
{
	auto account = repo->get(accountId);
	return SELF(*account, MoneySource).getAmount();
}

void AccountService::destroyAccount(const std::string& accountId)
{
	auto account = repo->remove(accountId);
	delete account;
}
