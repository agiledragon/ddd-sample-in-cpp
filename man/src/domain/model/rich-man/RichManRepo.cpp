#include "domain/model/rich-man/RichManRepo.h"


namespace
{
	RichManRepo* richRepo = nullptr;
}

void setRichManRepo(RichManRepo* repo)
{
	richRepo = repo;
}

RichManRepo* getRichManRepo()
{
	return richRepo;
}
