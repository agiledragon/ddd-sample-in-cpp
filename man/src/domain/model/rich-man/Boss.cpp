#include "domain/model/rich-man/Boss.h"
#include "domain/model/comm-role/ManInfo.h"


void Boss::askForLeave()
{

}

void Boss::assignTask()
{

}


std::string Boss::getAccountId() const
{
	return ROLE(ManInfo).getAccountId();
}
