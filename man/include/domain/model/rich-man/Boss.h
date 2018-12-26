#ifndef HF571CEA2_98B2_427E_B3FC_2D0562DA1F2C
#define HF571CEA2_98B2_427E_B3FC_2D0562DA1F2C


#include "domain/model/base/Role.h"
#include "domain/model/comm-role/Worker.h"

#include <string>

struct ManInfo;

struct Boss : Worker
{
	OVERRIDE(void askForLeave());
	OVERRIDE(void workOvertime());

	std::string getAccountId() const;

private:
	USE_ROLE(ManInfo);
};


#endif
