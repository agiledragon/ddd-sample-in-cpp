#include "domain/model/poor-man/PoorManRepo.h"

struct PoorManImpl : PoorManRepo
{
	OVERRIDE(void add(PoorMan* man))
	{

	}

	OVERRIDE(PoorMan* get(const std::string& manId))
	{
		return nullptr;
	}

	OVERRIDE(void update(PoorMan* man))
	{

	}

	OVERRIDE(PoorMan* remove(const std::string& manId))
	{
		return nullptr;
	}
};
