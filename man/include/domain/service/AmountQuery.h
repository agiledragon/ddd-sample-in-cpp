#ifndef H05208FB5_B13E_40EE_8053_72840AB59344
#define H05208FB5_B13E_40EE_8053_72840AB59344

#include "pub/base/Types.h"

#include <string>

struct RichManRepo;
struct PoorManRepo;
struct AccountRepo;

struct AmountQuery
{
	AmountQuery();

	U32 getRichManAmount(const std::string& manId);
	U32 getPoorManAmount(const std::string& manId);

private:
	RichManRepo* richRepo;
	PoorManRepo* poorRepo;
	AccountRepo* accountRepo;
};


#endif
