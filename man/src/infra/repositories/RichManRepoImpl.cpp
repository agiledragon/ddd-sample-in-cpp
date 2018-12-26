#include "domain/model/rich-man/RichManRepo.h"

struct RichManRepoImpl : RichManRepo
{
	OVERRIDE(void add(RichMan* man))
	{

	}

	OVERRIDE(RichMan* get(const std::string& manId))
	{
		return nullptr;
	}

	OVERRIDE(void update(RichMan* man))
	{

	}

	OVERRIDE(RichMan* remove(const std::string& manId))
	{
		return nullptr;
	}
};
