#ifndef H6B63B21A_32C3_4285_86B6_8291CE9062E8
#define H6B63B21A_32C3_4285_86B6_8291CE9062E8


#include "domain/model/base/Role.h"

struct Worker;

struct Parent : Role
{
	void attendShoolMeeting();
	void workOverWeekend();

private:
	USE_ROLE(Worker);
};


#endif
