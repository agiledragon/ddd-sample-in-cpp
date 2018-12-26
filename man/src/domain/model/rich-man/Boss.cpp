#include "domain/model/rich-man/Boss.h"
#include "domain/model/comm-role/ManInfo.h"


void Boss::askForLeave()
{

}

void Boss::workOvertime()
{

}


std::string Boss::getAccountId() const
{
	return ROLE(ManInfo).getAccountId();
}
