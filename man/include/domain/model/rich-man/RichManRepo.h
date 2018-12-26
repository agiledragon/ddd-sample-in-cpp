#ifndef H99C19BBC_6E22_4215_B73C_F5F62A000917
#define H99C19BBC_6E22_4215_B73C_F5F62A000917

#include "pub/base/Keywords.h"

#include <string>

struct RichMan;

struct RichManRepo
{
	virtual ~RichManRepo() = default;

	ABSTRACT(void add(RichMan* man));
	ABSTRACT(RichMan* get(const std::string& manId));
	ABSTRACT(void update(RichMan* man));
	ABSTRACT(RichMan* remove(const std::string& manId));
};

void setRichManRepo(RichManRepo* repo);
RichManRepo* getRichManRepo();

#endif
