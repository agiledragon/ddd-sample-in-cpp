#include "domain/model/account/Account.h"

Account::Account(const std::string& accountId, const std::string& phoneNumber, U32 initialAmount)
: AggregateRoot(accountId), AccountInfo(accountId), Balance(initialAmount), Phone(phoneNumber)
{

}
