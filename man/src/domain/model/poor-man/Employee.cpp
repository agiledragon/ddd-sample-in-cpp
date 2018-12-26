#include "domain/model/poor-man/Employee.h"
#include "domain/model/comm-role/ManInfo.h"


void Employee::askForLeave()
{

}

void Employee::workOvertime()
{

}

std::string Employee::getAccountId() const
{
	return ROLE(ManInfo).getAccountId();
}
