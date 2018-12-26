#include "domain/model/poor-man/PoorManRepo.h"


namespace
{
	PoorManRepo* poorRepo = nullptr;
}

void setPoorManRepo(PoorManRepo* repo)
{
	poorRepo = repo;
}

PoorManRepo* getPoorManRepo()
{
	return poorRepo;
}
