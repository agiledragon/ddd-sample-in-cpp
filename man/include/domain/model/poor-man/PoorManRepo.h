#ifndef H9F60428A_8726_49D2_84AA_D97457B9B9B4
#define H9F60428A_8726_49D2_84AA_D97457B9B9B4

#include "pub/base/Keywords.h"

#include <string>

struct PoorMan;

struct PoorManRepo
{
	virtual ~PoorManRepo() = default;

	ABSTRACT(void add(PoorMan* man));
	ABSTRACT(PoorMan* get(const std::string& manId));
	ABSTRACT(void update(PoorMan* man));
	ABSTRACT(PoorMan* remove(const std::string& manId));
};

void setPoorManRepo(PoorManRepo* repo);
PoorManRepo* getPoorManRepo();

#endif
