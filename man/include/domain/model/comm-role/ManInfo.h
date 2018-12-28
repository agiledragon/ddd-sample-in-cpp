#ifndef H03BFE543_F2B8_4144_8ECF_FEDDEF4E488B
#define H03BFE543_F2B8_4144_8ECF_FEDDEF4E488B

#include "pub/base/Types.h"

#include <string>

struct ManInfo
{
	ManInfo(const std::string& manId, const std::string& name,
			Gender gender, const std::string& phoneNumber, U32 initAmount);
	~ManInfo();

	std::string getAccountId() const;

private:
	std::string manId;
	std::string name;
	Gender gender;
	std::string phoneNumber;
	std::string accountId;
};


#endif
