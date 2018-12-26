#ifndef H5DE0236D_5B87_4915_B145_8EA3702DE19F
#define H5DE0236D_5B87_4915_B145_8EA3702DE19F


#include "domain/model/base/AggregateRoot.h"
#include "domain/model/rich-man/Boss.h"
#include "domain/model/comm-role/Parent.h"
#include "domain/model/comm-role/ManInfo.h"


struct RichMan : AggregateRoot
			   , Parent
			   , Boss
			   , private ManInfo
{
	RichMan(const std::string& manId, const std::string& name, Gender gender,
			const std::string& phoneNumber, U32 initAmount);

private:
	IMPL_ROLE(Worker);
	IMPL_ROLE(ManInfo);
};


#endif



