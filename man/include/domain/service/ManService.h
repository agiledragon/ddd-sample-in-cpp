#ifndef HF2EB0D02_9814_4213_91CB_FEC2EEE1A981
#define HF2EB0D02_9814_4213_91CB_FEC2EEE1A981

#include "domain/model/poor-man/PoorManRepo.h"
#include "domain/model/rich-man/RichManRepo.h"
#include "pub/base/Types.h"


struct ManService
{
	ManService();

	std::string allocManId(const std::string& name);
	void transferMoney(const std::string& richManId, const std::string& poorManId, U32 amount);

private:
	RichManRepo* richRepo;
	PoorManRepo* poorRepo;
};


#endif
