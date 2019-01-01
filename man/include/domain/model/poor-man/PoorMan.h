#ifndef H5A83A10C_9C72_4202_8BBA_1AAFA818711B
#define H5A83A10C_9C72_4202_8BBA_1AAFA818711B


#include "domain/model/base/AggregateRoot.h"
#include "domain/model/comm-role/Parent.h"
#include "domain/model/comm-role/ManInfo.h"
#include "domain/model/poor-man/Employee.h"
#include "domain/model/poor-man/Cooker.h"


struct PoorMan : AggregateRoot
			   , Parent
			   , Employee
			   , Cooker
			   , private ManInfo
{
	PoorMan(const std::string& manId, const std::string& name, Gender gender,
			const std::string& phoneNumber, U32 initAmount);

private:
	IMPL_ROLE(Worker);
	IMPL_ROLE(ManInfo);
};

#endif
