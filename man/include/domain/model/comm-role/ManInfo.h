#ifndef H03BFE543_F2B8_4144_8ECF_FEDDEF4E488B
#define H03BFE543_F2B8_4144_8ECF_FEDDEF4E488B

#include "pub/base/Types.h"
#include "pub/base/Keywords.h"
#include "domain/model/base/ValueObject.h"

#include <string>

struct ManInfo : ValueObject
{
	ManInfo(const std::string& manId, const std::string& name,
			Gender gender, const std::string& phoneNumber, U32 initAmount);
	virtual ~ManInfo();

	OVERRIDE(bool operator==(ValueObject* rhs));

	std::string getAccountId() const;

private:
	std::string manId;
	std::string name;
	Gender gender;
	std::string phoneNumber;
	std::string accountId;
};


#endif
