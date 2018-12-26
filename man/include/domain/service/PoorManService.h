#ifndef H277870A9_EBF2_4960_9727_054C814AC5CD
#define H277870A9_EBF2_4960_9727_054C814AC5CD

#include "pub/base/Types.h"

#include <string>

struct PoorManRepo;

struct PoorManService
{
	PoorManService();

	std::string createMan(const std::string& name, Gender gender,
			const std::string& phoneNumber);
	U32 getAmount(const std::string& manId);
	void destroyMan(const std::string& manId);

private:
	PoorManRepo* repo;
};


#endif
