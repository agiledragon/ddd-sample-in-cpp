#include "domain/model/comm-role/Parent.h"
#include "domain/model/comm-role/Worker.h"
#include "pub/log/log.h"

void Parent::attendShoolMeeting()
{
	ROLE(Worker).askForLeave();
	INFO_LOG("go to school");
	INFO_LOG("attend meeting");
	INFO_LOG("go home");
}

void Parent::workOverWeekend()
{
	INFO_LOG("send children to grandparent");
	ROLE(Worker).workOvertime();
	INFO_LOG("pick up children from grandparent");
}
