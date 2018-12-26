#ifndef H9A916E58_7736_4295_9076_1EE20A390EA9
#define H9A916E58_7736_4295_9076_1EE20A390EA9

#include "domain/model/comm-role/Worker.h"
#include "domain/model/base/Role.h"

#include <string>

struct ManInfo;

struct Employee : Worker
{
	OVERRIDE(void askForLeave());

	void workOvertime();

	std::string getAccountId() const;

private:
	USE_ROLE(ManInfo);
};



#endif
